#include <iostream>
#include "stack.h"
using namespace std;


DynamicStringStack::DynamicStringStack()//Constructor
{
	top=NULL;
}


void DynamicStringStack::push(cordinate elmt)//Push back elements to the stack
{
	StackNode *newNode;

	newNode = new StackNode;
	newNode->value = elmt;

	if(!isEmpty())
	{
		top = newNode;
		newNode->prev = NULL;
	}
	else
	{
		newNode->prev = top;
		top = newNode;
	}
}

void DynamicStringStack::pop(cordinate &elmt)//Pop up elements from the stack
{
	StackNode *temp;

	if(!isEmpty())
	{
		cout<<"Stack is empty!\n";
	}

	else 
	{
		elmt = top->value;
		temp = top->prev;
		delete top;
		top = temp;
	}
}


bool DynamicStringStack::isEmpty()//If the stack is empty check function
{
	bool status;

	if(top!=NULL)
		status=true;

	else 
		status=false;

	return status;
}

DynamicStringStack::~DynamicStringStack()//destructor function of the stack member function
{
	string value;  
	StackNode *temp;
	while(isEmpty())
	{
		temp=top->prev;
		delete top;
		top=temp;
	}
}