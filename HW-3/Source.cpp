#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "stack.h"
#include <iomanip> 

bool rowchecker(string srows){//this function checks the row input
	int counter3=0;
	bool flag=true;
	int rows;
	for(int i=0;i<srows.length();i++){
		if(srows.at(i)>='0'&&srows.at(i)<='9'){
			counter3++;
		}
	}

	if(counter3==srows.length()){
		rows=stoi(srows);
		if(rows>=3){
			flag=false;
		}
		else{
			cout<<rows<<" is not valid!"<<endl;;
		}
	}
	else{
		cout<<srows<<" is not valid!"<<endl;
	}
	return flag;
}

bool columnschecker(string scolumns){//this function checks the column input
	int counter4=0;
	bool flag=true;
	int columns;
	for(int k=0;k<scolumns.length();k++){
		if(scolumns.at(k)>='0'&&scolumns.at(k)<='9'){
			counter4++;
		}
	}

	if(counter4==scolumns.length()){
		columns=stoi(scolumns);
		if(columns>=3){
			flag=false;
		}
		else{
			cout<<columns<<" is not valid!"<<endl;
		}
	}
	else{
		cout<<scolumns<<" is not valid!"<<endl;
	}
	return flag;
}
bool filling_char_check(char fill){//this function checks the filling char input by looking is it not 'x' or 'X'
	bool flag=true;
	if(fill=='x'||fill=='X'){
		cout<<"Filling char is not valid!"<<endl;
	}
	else{
		flag=false;
	}
	return flag;
}
int main(){

	string filename;
	ifstream matrix;
	char **mat; 
	int rows, columns;
	string srows, scolumns;
	string line;
	int xpos;
	int ypos;
	string x;
	string y;
	bool flag=true;
	bool flag2=true;
	bool flag3=true;
	bool flag4=true;
	bool flag5=true;
	char fill;
	while(flag3){//in this loop rowchecker function calls 
		cout<<"Enter the number of rows: ";
		cin>>srows;
		flag3=rowchecker(srows);
	}

	while(flag4){//in this loop columnschecker function calls
		cout<<"Enter the number of columns: ";
		cin>>scolumns;
		flag4=columnschecker(scolumns);
	}

	columns=stoi(scolumns);
	rows=stoi(srows);

	mat = new char*  [rows];  //it makes a new matrix
	for (int i = 0; i<rows; i++){
		mat[i] = new char  [columns]; 
	}


	cout<<"Please enter file name:";
	cin>>filename;
	matrix.open(filename);
	while(matrix.fail()){//continue until the true matrix input
		matrix.clear();//clear the error
		cout<<"Cannot find a file named matrix"<< endl;
		cout<<"Please enter file name:";
		cin>>filename;
		matrix.open(filename);

	}	
	int k=0;
	while(!matrix.eof()){//reads the file and fill the matrix by the chars of the txt
		getline(matrix, line);
		for(int j=0;j<columns;j++){
			mat[k][j]=line.at(j);
		}
		if(rows-1>=k){
			k++;
		}
	}


	while(flag){//in this while loop the program checks the starting point on the the matrix if it occupied or invalid cordinate
		cout<<"Enter the starting point: "<<endl;
		cin>>x>>y;
		int counter=0;
		int counter2=0;
		for(int i=0;i<x.length();i++){
			if(x.at(i)>='0'&&x.at(i)<='9'){
				counter++;
			}
		}
		for(int k=0;k<y.length();k++){
			if(y.at(k)>='0'&&y.at(k)<='9'){
				counter2++;
			}
		}
		if(counter==x.length()&&counter2==y.length()){
			xpos=stoi(x);
			ypos=stoi(y);
			if(xpos<=rows-1&&ypos<=columns-1){
				if(mat[xpos][ypos]!='X'){
					flag=false;
				}
				else{
					cout<<"Starting point is already occupied."<<endl;
					cout<<"Terminating... "<<endl;
					flag=false;
					flag5=false;
				}
			}
			else{
				cout<<"Invalid coordinate!"<<endl;
			}
		}
		else{
			cout<<"Invalid coordinate!"<<endl;
		}
	}
	while(flag5){

		while(flag2){//in this loop filling_char_check function calls
			cout<<"Enter the filling char: "<<endl;
			cin>>fill;
			flag2=filling_char_check(fill);
		}


		DynamicStringStack mystack;//make a new stack
		cordinate temp(xpos,ypos);//make a new cordinate
		mystack.push(temp);//the cordinate is push to the stack by using push member function
		mat[temp.x][temp.y]=fill;
		while(mystack.isEmpty()){//this loop ends until the matrix blank point which are neighbor to the starting point are full
			if(mat[(temp.x)+1][temp.y]==' '){
				temp.x=temp.x+1;
				mystack.push(temp);//the cordinate is push to the stack by using push member function
				mat[temp.x][temp.y]=fill;
			}
			else if(mat[(temp.x)][temp.y+1]==' '){
				temp.y=temp.y+1;
				mystack.push(temp);//the cordinate is push to the stack by using push member function
				mat[temp.x][temp.y]=fill;
			}
			else if(mat[(temp.x)][temp.y-1]==' '){
				temp.y=temp.y-1;
				mystack.push(temp);//the cordinate is push to the stack by using push member function
				mat[temp.x][temp.y]=fill;
			}
			else if(mat[(temp.x)-1][temp.y]==' '){
				temp.x=temp.x-1;
				mystack.push(temp);//the cordinate is push to the stack by using push member function
				mat[temp.x][temp.y]=fill;
			}
			else{
				mystack.pop(temp);//the cordinate is erase from the top of the stack by using pop member function
			}
		}
		for(int a=0;a<rows;a++){//print the finall version of the matrix
			for(int b=0;b<columns;b++){
				cout<< setw(2) << mat[a][b];
			}
			cout<<endl;
		}
		flag5=false;
	}
	return 0;
}