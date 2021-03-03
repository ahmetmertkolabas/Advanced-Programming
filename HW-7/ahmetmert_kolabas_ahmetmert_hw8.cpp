#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "ahmetmert_kolabas_ahmetmert_hw8_DynIntQueue.h"

using namespace std;

HW8DynIntQueue myQueue;
mutex myMutex, coutMutex;
int counter = 0;


#include <random> #include <time.h> 

int random_range(const int & min, const int & max) {    //this function creates a random number which is between  min and max parameters
	static mt19937 generator(time(0));     
	uniform_int_distribution<int> distribution(min, max);     
	return distribution(generator); 
} 


void producer(int customer_count,int arrival_time)//this function starts the customer threat which enqueue a element in the queue
{
	for(int i = 1; i <=customer_count; i++)
	{
		myMutex.lock();
		coutMutex.lock();
		myQueue.enqueue(i);
		myMutex.unlock();

		time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); //calculate the process time
		struct tm *ptm = new struct tm; 
		localtime_s(ptm, &tt); 
		cout <<"New customer with ID "<<i<<" has arrived (queue size is "<<myQueue.getCurrentSize()<<"):  "<< put_time(ptm,"%X") <<endl;
		coutMutex.unlock();
		this_thread::sleep_for(chrono::seconds(arrival_time)); 
	}
}

void consumer1(int casId,int customer_count,int checkout_time)//this function starts the first cashier threat which dequeue a element from the queue
{
	this_thread::sleep_for(chrono::seconds(checkout_time));
	int item;
	while(counter!=customer_count)
	{	
		myMutex.lock();
		coutMutex.lock();
		if (!myQueue.isEmpty()) 
		{  
			myQueue.dequeue(item);
			counter++;
			myMutex.unlock();

			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); //calculate the process time
			struct tm *ptm = new struct tm; 
			localtime_s(ptm, &tt); 
			cout<<"Cashier "<<casId<<" started transaction with customer "<<item<<" (queue size is "<<myQueue.getCurrentSize()<<"):  "<< put_time(ptm,"%X") <<endl;
			coutMutex.unlock();

			this_thread::sleep_for(chrono::seconds(checkout_time)); // simulation for consume

			coutMutex.lock();
			tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			//ptm = new struct tm; 
			localtime_s(ptm, &tt); 
			cout<<"Cashier "<<casId<<" finished transaction with customer "<<item<<" "<<put_time(ptm,"%X") <<endl;
			coutMutex.unlock();
		}
		else
		{
			myMutex.unlock();
			coutMutex.unlock();
		}
	}
}

void consumer2(int casId,int customer_count,int checkout_time,int cashier2_threshold)//this function starts the second cashier threat which dequeue a element from the queue and starts the process after the cashier2_threshold input
{
	this_thread::sleep_for(chrono::seconds(checkout_time));
	int item;
	while(counter!=customer_count)
	{	
		if(myQueue.getCurrentSize()>=cashier2_threshold){
			myMutex.lock();
			coutMutex.lock();
			if (!myQueue.isEmpty()) 
			{  
				myQueue.dequeue(item);
				counter++;
				myMutex.unlock();

				time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); //calculate the process time
				struct tm *ptm = new struct tm; 
				localtime_s(ptm, &tt); 
				cout<<"Cashier "<<casId<<" started transaction with customer "<<item<<" (queue size is "<<myQueue.getCurrentSize()<<"):  "<< put_time(ptm,"%X") <<endl;
				coutMutex.unlock();

				this_thread::sleep_for(chrono::seconds(checkout_time)); // simulation for consume

				coutMutex.lock();
				tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
				//ptm = new struct tm; 
				localtime_s(ptm, &tt); 
				cout<<"Cashier "<<casId<<" finished transaction with customer "<<item<<" "<<put_time(ptm,"%X") <<endl;
				coutMutex.unlock();
			}
			else
			{
				myMutex.unlock();
				coutMutex.unlock();
			}
		}
		else{
			continue;
		}
	}
}

int main(){
	int customer_count;
	int cashier2_threshold;
	int arrival_time; 
	int  checkout_time ;
	int min;
	int max;
	cout<<"Please enter the total number of customers: ";
	cin>>customer_count;
	cout<<"Please enter the number of customers waiting in the queue to open the second cashier:";
	cin>>cashier2_threshold;
	cout<<"Please enter the inter-arrival time range between two customers: "<<endl;
	cout<<"Min: ";
	cin>>min;
	cout<<"Max: ";
	cin>>max;
	arrival_time=random_range(min,max);
	cout<<"Please enter the checkout time range of cashiers: "<<endl;
	cout<<"Min: ";
	cin>>min;
	cout<<"Max: ";
	cin>>max;
	checkout_time=random_range(min,max);
	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	cout<<"Simulation starts "<< put_time(ptm,"%X") <<endl;//cout the starting time 

	thread thr0(producer,customer_count,arrival_time);//the threat which use producer function
	thread thr1(consumer1, 1,customer_count,checkout_time);//the threat which use consumer1 function
	thread thr2(consumer2, 2,customer_count,checkout_time,cashier2_threshold);//the threat which use consumer2 function

	thr0.join();
	thr1.join();
	thr2.join();

	return 0;
}