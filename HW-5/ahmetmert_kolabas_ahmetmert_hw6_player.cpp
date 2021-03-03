
#include "ahmetmert_kolabas_ahmetmert_hw6_player.h"
#include "ahmetmert_kolabas_ahmetmert_hw6_board.h"
#include<iostream>
#include<string>

using namespace std;



void Player::move(int amount)//this function takes a integer parameter and goes that number of cells corespoinding the direction of the player object which calls
{
	bool flag=true;
	bool flag2=true;
	int R=this->row;
	int C=this->column;
	if(this->direction==1){
		while(flag){
			if(R==0){
				while(R==0){
					if(C!=5){
						while(5>C && amount>0){
							C++;
							amount--;
						}
					}
					while(1>R && amount>0){
						R++;
						amount--;
					}
					if(amount==0){
						flag=false;
						break;
					}
				}
			}	
			if(R!=0){
				while(R!=0){	
					if(C!=0){
						while(C>0 && amount>0){
							C--;
							amount--;
						}
					}
					while(R>0 && amount>0){
						R--;
						amount--;
					}
					if(amount==0){
						flag=false;
						break;
					}
				}
			}
		}
	}
	else{
		while(flag2){
			if(R==0){
				while(R==0){
					if(C!=0){
						while(C>0 && amount>0){
							C--;
							amount--;
						}
					}
					while(1>R && amount>0){
						R++;
						amount--;
					}
					if(amount==0){
						flag2=false;
						break;
					}
				}
			}	
			if(R!=0){
				while(R!=0){
					if(C!=5){
						while(5>C && amount>0){
							C++;
							amount--;
						}
					}
					while(R>0 && amount>0){
						R--;
						amount--;
					}
					if(amount==0){
						flag2=false;
						break;
					}
				}
			}
		}
	}
	this->row=R;
	this->column=C;

}
void Player::claimOwnership(){//if the cordinate is blank that the player object claim its ownership and the char is written at the direction on the matrix
	char ch;
	ch=board.getOwner(this->row,this->column);
	if(ch=='_'){
		board.setOwner(this->row,this->column,this->playerChar);
	}
}

bool Player::wins()//this function calls the countownedcells function and if the number is 7 than the player object which calls the function win the game
{
	int amount;
	amount=board.countOwnedCells(this->playerChar);
	if(amount==7){
		return true;
	}
	return false;
}

int Player::getRow(){//get the row of the player object on the matrix

	return this->row;
}

int Player::getCol(){//get the column of the player object on the matrix
	return this->column;
}