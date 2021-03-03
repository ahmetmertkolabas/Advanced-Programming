#ifndef _CARDLIST_H
#define _CARDLIST_H

#include <iostream>
using namespace std;

struct creditCardNode  { 
	string creditCardNo;  
	creditCardNode * next;    
	// constructors come here 
}; 

struct expirationNode {  
	int month, year;  
	creditCardNode * cHead;  
	expirationNode * next;  
	expirationNode * prev; 

	// constructors come here 
};

class CardList  { 
public:  
	CardList(); 
	//default constructor that creates an empty list  
	void insertCard (string creditCardNo, int month, int year);    
	//inserts a new card to the structure in sorted fashion  
	void displayListChronological ();  
	//displays entire structure in chronological order  
	void displayListReverseChronological ();  
	//displays entire structure in reverse chronological order  
	void cardSearch (string creditCardNo);  
	//displays all of the occurrences of the given card number  
	void bulkDelete (int month, int year);  
	//deletes all nodes up to and including given expiration date  
	void deleteAll (); 
	//deletes the entire structure 
private:
	bool stringSmaller(string a, string b);
	creditCardNode* insertCardNumber(creditCardNode * head, string cardNumber);
	void display(int direction);
	void printCardNumber(creditCardNode * tmp);
	int stringComparison(string, string);
	expirationNode * head1;  
	expirationNode * tail; 

	// any helper functions you see necessary 
}; 

#endif