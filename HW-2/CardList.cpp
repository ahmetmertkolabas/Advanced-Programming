#include <iostream>
#include <string>
#include"CardList.h"
using namespace std;

CardList::CardList(){
	head1=NULL;
	tail=NULL;
} 
void CardList::insertCard (string creditCardNo, int month, int year){
	expirationNode * tmp=head1;
	if(head1==NULL) {
		head1 = tail = new expirationNode();
		head1->month = month;
		head1->year = year;
		head1->cHead=NULL;
		head1->cHead = insertCardNumber(head1->cHead,creditCardNo);
		head1->next = head1->prev =NULL;
		cout<<creditCardNo<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
	} 
	else if(year < head1->year || (year==head1->year && month<head1->month)) {
		head1 = new expirationNode();
		head1->month = month;
		head1->year = year;		
		head1->cHead = NULL;
		head1->cHead = insertCardNumber(head1->cHead, creditCardNo);
		head1->next=tmp;
		tmp->prev =head1;
		head1->prev=NULL;
		cout<<creditCardNo<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
	}
	else {
		while(tmp!=NULL){

			if(tmp->month == month && tmp->year == year){
				tmp->cHead = insertCardNumber(tmp->cHead, creditCardNo);
				cout<<creditCardNo<<" "<<month<<" "<<year<<" :inserted to an existing expiration date node"<<endl;
				return;
			}
			else if(tmp->next == NULL){
				tail = new expirationNode();
				tail->month = month;
				tail->year = year;
				tail->cHead = NULL;
				tail->cHead = insertCardNumber(tail->cHead, creditCardNo);
				tail->next=NULL;
				tail->prev=tmp;
				tmp->next=tail;
				cout<<creditCardNo<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				return;
			}
			else if(tmp->next->year > year || (tmp->next->year == year && tmp->next->month > month)){
				expirationNode * nxt = tmp->next;
				tmp->next = new expirationNode();
				tmp->next->month = month;
				tmp->next->year = year;
				tmp->next->cHead= NULL;
				tmp->next->cHead = insertCardNumber(tmp->next->cHead, creditCardNo);
				tmp->next->next = nxt;
				nxt->prev = tmp->next;
				tmp->next->prev = tmp;
				cout<<creditCardNo<<" "<<month<<" "<<year<<": added to a new expiration date node"<<endl;
				return;
			}
			tmp = tmp->next;
		}
	}
}


creditCardNode * CardList::insertCardNumber(creditCardNode * head, string cardNumber){
	creditCardNode * tmp = head;
	if(head==NULL){
		head = new creditCardNode();
		head->creditCardNo = cardNumber;
		head->next = NULL;
	}
	else if(stringComparison(cardNumber,head->creditCardNo) == -1){
		head = new creditCardNode();
		head->creditCardNo = cardNumber;
		head->next = tmp;
	}
	else {
		while(tmp!=NULL){
			if(stringComparison(tmp->creditCardNo,cardNumber) == 0){
				return head; 
			}
			else if(tmp->next == NULL){
				tmp -> next = new creditCardNode();
				tmp->next->creditCardNo = cardNumber;
				tmp->next->next = NULL; 
				return head;
			}
			else if(stringComparison(cardNumber,tmp->next->creditCardNo)==-1){
				creditCardNode * nxt = new creditCardNode();
				nxt->next = tmp->next;
				tmp->next = nxt;
				nxt->creditCardNo = cardNumber;
				return head;
			}
			tmp=tmp->next;
		}
	}
	return head;
}


void CardList::displayListChronological (){
	display(1);
} 


void CardList::displayListReverseChronological (){
	display(2);
}  


void CardList::cardSearch (string creditCardNo){
	expirationNode * tmp=head1;
	bool flag=false;
	while(tmp!=NULL){
		creditCardNode * tmp2 = tmp->cHead;
		while(tmp2!=NULL){
			if(tmp2->creditCardNo==creditCardNo){
				cout<<"There exists a credit card given number "<<creditCardNo<<" with expiration date: "<<tmp->month<<" "<<tmp->year<<endl<<endl;
				flag=true;
			}
			tmp2=tmp2->next;
		} 
		tmp=tmp->next;
	}	
	if(flag==false){
		cout<<"There is no credit card with given credit card number: "<<creditCardNo<<endl<<endl;
	}
}


void CardList::bulkDelete (int month, int year){
	expirationNode * tmp=head1;
	expirationNode * tmp2=head1;
	expirationNode * tmp3;
	int flag=1;
	while(flag){
		if(tmp->next->year > year || (tmp->next->year == year && tmp->next->month > month))
		{
			head1=tmp->next;
			while(tmp2!=head1){
				tmp2=tmp2->next;
				cout<<"Node with expiration date "<<tmp2->prev->month<<" "<<tmp2->prev->year<<"and the following credit cards have been deleted! "<<endl;
				creditCardNode* ptr = tmp2->prev->cHead;
				int cnt = 1;
				while (ptr)
				{
					creditCardNode* ptr2 = ptr;
					cout << cnt << ") " << ptr->creditCardNo << endl;
					ptr = ptr->next;
					delete ptr2;
					cnt++;
				}
				delete tmp2->prev;
			}
			head1->prev=NULL;
			flag=0;
		}
		if(tmp->year==year&&tmp->month==month){
			head1=tmp->next;
			while(tmp2!=head1){
				tmp2=tmp2->next;
				cout<<"Node with expiration date "<<tmp2->prev->month<<" "<<tmp2->prev->year<<"and the following credit cards have been deleted! "<<endl;
				creditCardNode* ptr = tmp2->prev->cHead;
				int cnt = 1;
				while (ptr)
				{
					creditCardNode* ptr2 = ptr;
					cout << cnt << ") " << ptr->creditCardNo << endl;
					ptr = ptr->next;
					delete ptr2;
					cnt++;
				}
				delete tmp2->prev;
			}
			head1->prev=NULL;
			flag=0;
		}
		if((tail->year==year&&tail->month==month)||(tail->year<year)||(tail->year==year&&tail->month<month)){
			while(tmp2!=NULL){
				cout<<"Node with expiration date "<<tmp2->month<<" "<<tmp2->year<<"and the following credit cards have been deleted! "<<endl;
				creditCardNode* ptr = tmp2->cHead;

				int cnt = 1;
				while (ptr)
				{
					creditCardNode* ptr2 = ptr;
					cout << cnt << ") " << ptr->creditCardNo << endl;
					ptr = ptr->next;
					delete ptr2;
					cnt++;
				}
				tmp3=tmp2;
				tmp2=tmp3->next;
				delete tmp3;
			}
			flag=0;
		}
		tmp=tmp->next;
	}

}
//deletes all nodes up to and including given expiration date  
void CardList::deleteAll () {
	expirationNode * tmp=head1;
	expirationNode * tmp2=head1;
	while(tmp!=NULL){
		creditCardNode* ptr =tmp->cHead;
		creditCardNode* ptr2 =tmp->cHead;
		while(ptr!=NULL){
			ptr=ptr->next;
			delete ptr2;
			ptr2=ptr;
		}
		tmp=tmp->next;
		delete tmp2;
		tmp2=tmp;
	}
	cout<<"All the nodes have been deleted!"<<endl<<"Terminating!!!";
}

//deletes the entire structure 

int CardList::stringComparison(string a, string b){
	for(int i=0;i<a.length();i++){
		if(a.at(i) < b.at(i)){
			return -1;
		}
		else if(b.at(i)<a.at(i)){
			return 1;
		}
	}
	return 0;
}


void CardList::printCardNumber(creditCardNode * tmp){
	int i=1;
	while(tmp!=NULL){
		cout<<i<<")"<<tmp->creditCardNo<<endl;
		tmp = tmp->next;
		i++;
	}
	cout<<"------------------- "<<endl;
}


void CardList::display(int direction){
	expirationNode * tmp;
	if(direction == 1){
		tmp = head1;
	}
	else{
		tmp = tail;
	}
	while(tmp!=NULL){
		cout<<"Expiration Date: "<<tmp->month<<" "<<tmp->year<<endl;
		printCardNumber(tmp->cHead);
		if(direction == 1){
			tmp = tmp->next;
		}
		else{
			tmp = tmp->prev;
		}
	}
}
