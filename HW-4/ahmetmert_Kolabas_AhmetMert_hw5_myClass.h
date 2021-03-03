#ifndef _AHMETMERT_KOLABAS_AHMETMERT_HW5_H
#define _AHMETMERT_KOLABAS_AHMETMERT_HW5_H
#include <string>;
#include <iostream>;
using namespace std;

class IntegerSet 
{
private:
	int* vector;
	int size;

public:
	IntegerSet(); // empty constructor
	IntegerSet(int); // constructor with vector size
	IntegerSet(const IntegerSet &); // copy constructor
	~IntegerSet(); // destructor
	 const IntegerSet& operator=(const IntegerSet &); // assignment operator (=)
	//IntegerSet operator+=(const IntegerSet &); // += operator
	IntegerSet  operator +(const IntegerSet &)const; // + operator
	IntegerSet operator+(const int &);//take the union of the the left hand side and right hand side int
	IntegerSet operator*(const IntegerSet &);//take the intersection of two sides
	bool operator!=(IntegerSet &);//check if two side is not equal
	bool operator <=(const IntegerSet &);//check if it is a subset
	int getElement(int)const; // get element in specified index
	void setSize(int); // set size of the vector
	int getSize()const; // get size of the vector
};

const IntegerSet & operator+=(IntegerSet & lhs, const IntegerSet & rhs);//take the union of the left hand side and right hand side and make it equal to left hand side

ostream & operator << (ostream &,const IntegerSet &);//ostream function for integerset object

bool operator <= (const int &,const IntegerSet &);//look if the left hand side int value is the subset of the  right hand size

#endif

