#ifndef __STACK_H
#define __STACK_H

#include "Node.h"

class Stack
{
public:
	Stack();//ctor
	Stack(Stack& other);//copy ctor
	~Stack();//dtor

	void MakeEmpty();//make stack empty
	bool IsEmpty();// check if stack is empty
	void Push(Point& point);// push node to stack
	Point& Pop();// pop node from stack
	const Point& Top()const;//return the top node in stack

private:
	Node* m_top;

};



#endif // !__STACK_H

