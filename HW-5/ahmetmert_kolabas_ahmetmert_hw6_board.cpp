
#include "ahmetmert_kolabas_ahmetmert_hw6_board.h"
#include <iostream>
using namespace std;


Board::Board()//the constructor of board object
{
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			myBoard[i][j] = '_';
		}
	}
}

char Board::getOwner(int row,int col){//returns what is inside that cordinate in the matrix

	return myBoard[row][col];


}

void Board::setOwner(int row,int col,char ch){//set the owner of the cordinate in the matrix

	myBoard[row][col]=ch;

}

bool Board::isFull()const{//boolean function that says if the matrix is full

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(myBoard[i][j]=='_'){

				return false;
			}
		}
	}
	return true;
}

void Board::displayBoard()const{//display the board object matrix

	cout << "Board: " << endl;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			cout << myBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Board::countOwnedCells(char ch)const{//count the cells whic is written char in the parameter
	int amount=0;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(myBoard[i][j]==ch){
				amount++;
			}
		}
	}
	return amount;
}
