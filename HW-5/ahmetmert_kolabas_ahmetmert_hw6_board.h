
#ifndef _AHMETMERT_KOLABAS_AHMETMERT_HW6_BOARD_H
#define _AHMETMERT_KOLABAS_AHMETMERT_HW6_BOARD_H
#include<string>
using namespace std;

class Board
{
public:
	Board();
	void setOwner(int,int,char);
	char getOwner(int,int);
	void displayBoard()const;
	bool isFull()const;
	int countOwnedCells(char)const;
private:
	char myBoard[2][6];
};
#endif