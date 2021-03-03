//Ahmet Mert Kolabas-25363

#include <iostream>
#include <string>


using namespace std;


int main(){
	string code;
	string plaintext;
	unsigned char c;
	unsigned char transformch;
	int count=0;
	unsigned char ch = 0;
	bool flag=true;
	cout<<"*** Welcome to the Simple Data Encryption Application ***"<<endl;
	cout <<"Please enter the encryption key: ";
	if(!getline (cin, code)){
	flag=false;
	}
	
	while(flag){
		cout << "Please enter the plaintext to be encrypted: ";
		getline (cin,plaintext);
		if(!cin.good()){//testing if input is valid
			flag=false;
		}
		if(flag==true){
			cout<<"Ciphertext: ";
			for(int i=0;i<plaintext.length();i++){//look for all chars in plaintext string
				if(count==code.length()){
					count=0;
				}
				c =plaintext[i];//take first char of the plain text and say c
				if ( c & 0x01 ){//look if the 0th bit is 1
					ch=ch | 0x04;//make the 2th bit 1 of ch
				}
				if(c & 0x02){//look if the 1th bit is 1
					ch= ch | 0x01;//make the 0th bit 1 of ch
				}
				if(c & 0x04){//look if the 2th bit is 1
					ch= ch | 0x08;//make the 3th bit 1 of ch
				}
				if(c & 0x08){//look if the 3th bit is 1
					ch= ch | 0x02;//make the 1th bit 1 of ch
				}
				if(c & 0x10){//look if the 4th bit is 1
					ch= ch | 0x40;//make the 7th bit 1 of ch
				}
				if(c & 0x20){//look if the 5th bit is 1
					ch= ch | 0x10;//make the 4th bit 1 of ch
				}
				if(c & 0x40){//look if the 6th bit is 1
					ch= ch | 0x80;//make the 7th bit 1 of ch
				}
				if(c & 0x80){//look if the 7th bit is 1
					ch= ch | 0x20;//make the 6th bit 1 of ch
				}
				transformch=ch^code[count];//xor permuted char and code string first char
				cout << hex << (int) transformch;//make the input in hexadecimal format
				ch=0;
				count++;
			}
			cout<<endl<<endl;
			count=0;
		}
	}
	return 0;
}