#include <iostream>
#include "ahmetmert_Kolabas_AhmetMert_hw5_myClass.h"

using namespace std;

/* Begin: code taken from MathVector.cpp */ 

IntegerSet ::IntegerSet()// constructor
{
	size = 0;
	vector = NULL;
}


IntegerSet ::IntegerSet(int psize)// constructor with vector size
{
	vector = new int[psize];
	size = psize;
	for(int i=0;i<size;i++){
		vector[i]=i;
	}
}


IntegerSet::~IntegerSet()// destructor
{
	size = 0;
	delete[] vector;
}


IntegerSet::IntegerSet(const IntegerSet & copy)// copy constructor - deep copy
{
	size = copy.size;
	vector = new int[size]; // deep copy

	for(int i = 0; i < size; i++)
	{
		vector[i] = copy.vector[i];
	}
}


const IntegerSet& IntegerSet::operator=(const IntegerSet & rhs)// assignment operator
{
	if (this != &rhs) // if they are not already equal
	{
		
		
		delete[] vector;// first delete left hand side
		size = 0;
		
		size = rhs.size;
		vector = new int[size]; // create new vector for left hand side

		for(int i = 0;i <size; i++)
		{
			vector[i] = rhs.vector[i]; // assign content
		}
	}

	return *this;
}
/* End: code taken from MathVector.cpp */

const IntegerSet & operator+=(IntegerSet& lhs,const IntegerSet& rhs){//take the union of the left hand side and right hand side and make it equal to left hand side
	lhs=lhs + rhs;
	return lhs;
}




bool IntegerSet::operator!=(IntegerSet & rhs){//look if the left hand side and right hand side is not equal than returns true
	if((rhs.size==0)&&(size!=0)){
		return true;
	}
	int amount=0;
	for(int i=0;i<size;i++){
		if(vector[i]==rhs.vector[i]){
			amount++;
		}
	}
	if(amount==rhs.size){
		return false;
	}
	else{
		return true;
	}
}


IntegerSet IntegerSet::operator+(const int & rhs){//take the union of the left hand side and int
	bool flag=true;
	for(int i=0;i<size;i++){

		if(vector[i]==rhs){
			flag=false;
		}
	}
	if(flag){
		IntegerSet result(size+1);
		if(size==0){
			result.vector[0]=rhs;

		}
		else{
			for(int i=0;i<size;i++){
				result.vector[i]=vector[i];
			}
			result.vector[size]=rhs;

		}
		return result;	
	}
	else{
		return *this;
	}
}
// + operator

IntegerSet  IntegerSet::operator+(const IntegerSet & rhs)const//take the union of the left hand size and right hand size
{
	bool flag= true;
	IntegerSet copy(rhs);
	for(int i=0;i<size;i++){
		for(int a=0;a<rhs.size;a++){
			if(vector[i]==rhs.vector[a]){
				flag=false;
				break;
			}
		}
		if(flag==true){
			copy=copy+vector[i];
		}
		else{
			flag=true;
		}
	}
	return copy;

}
IntegerSet IntegerSet::operator*(const IntegerSet & rhs){//take the intersection of left hand size and right hand size

	int amount=0;
	for(int i=0;i<size;i++){
		for(int a=0;a<rhs.size;a++){
			if(vector[i]==rhs.vector[a]){
				amount++;
			}
		}
	}
	IntegerSet result(amount);
	for(int i=0;i<size;i++){
		for(int a=0;a<rhs.size;a++){
			if(vector[i]==rhs.vector[a]){
				result.vector[a]=rhs.vector[a];
			}
		}
	}
	return result;
}

bool IntegerSet::operator <=(const IntegerSet & rhs){//look if the left hand side is the subset of the right hand side
	bool flag=false;
	for(int i=0;i<size;i++){
		for(int a=0;a<rhs.size;a++){
			if(vector[i]==rhs.vector[a]){
				flag=true;
			}
		}
	}
	return flag;
}

bool operator <= (const int & lhs,const IntegerSet & set){//look if the left hand side int value is the subset of the  right hand size
	bool flag=false;
	int length=set.getSize();
	for(int i=0;i<length;i++){
		if(lhs==set.getElement(i)){
			flag=true;
		}
	}
	return flag;
}


ostream & operator << (ostream & cout,const IntegerSet & set){//ostream function for integerset object
	int length=set.getSize();
	cout<<"{";
	for(int i=0;i<length-1;i++){
		cout<<set.getElement(i)<<", ";
	}
	if(length==0){
		cout<<"}";
	}
	else{
		cout<<set.getElement(length-1)<<"}";
	}
	return cout;
}

/* Begin: code taken from MathVector.cpp */ 

void IntegerSet::setSize(int psize)// set size of the vector
{
	size = psize;
	vector = new int[size];
}


int IntegerSet::getSize()const// get size of the vector
{
	return size;
}


int IntegerSet::getElement(int index)const// get element in the specified index
{
	return vector[index];
}

/* End: code taken from MathVector.cpp */