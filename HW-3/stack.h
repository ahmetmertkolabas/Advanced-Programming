#ifndef DYNAMICSTRINGSTACK_H
#define DYNAMICSTRINGSTACK_H

#include <string>
using namespace std;
struct cordinate//cordinate struct
{
	int x,y;
	cordinate(){}
	cordinate(int x, int y):x(x),y(y){}
};
struct StackNode//stacknode struct
{
	cordinate value;
	StackNode *prev;
};


class DynamicStringStack//class of the DynamicStringStack
{
	private:
		StackNode *top;

	public:
		DynamicStringStack(void);
		void push(cordinate);
		void pop(cordinate &);
		bool isEmpty(void);
		~DynamicStringStack();
};


#endif