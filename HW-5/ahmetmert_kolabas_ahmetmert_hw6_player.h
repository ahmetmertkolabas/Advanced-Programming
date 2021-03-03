#ifndef _AHMETMERT_KOLABAS_AHMETMERT_HW6_PLAYER_H
#define _AHMETMERT_KOLABAS_AHMETMERT_HW6_PLAYER_H
#include "ahmetmert_kolabas_ahmetmert_hw6_board.h"

#include<string>
#include<iostream>
using namespace std;



class Player
{
public:
	Player();
	Player::Player(Board &myboard,char c,int direct)//constructor of the player object and the board object is shared with the referance type using the same board of the board class have
		: board(myboard), playerChar(c),direction(direct),row(0),column(0)
	{ }
	void move(int);
	void claimOwnership();
	bool wins();
	int getRow();
	int getCol();
private:
	Board &board;
	char playerChar;
	int direction;
	int row;
	int column;
};

#endif