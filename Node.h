#ifndef __NODE_H
#define __NODE_H

#include "Point.h"

class Node
{
public:
	Node(Point & point);//ctor
	Node(Point& point, Node* next);//ctor
	Node(Node& other);//copy cttor
	~Node() = default;//dtor
	

	void setNext(Node* next);//set next node


	Node* getNext()const;//get the next node
	Point& getPoint();// get the point


private:
	Node* m_next;
	Point m_point;
};


#endif // !__NODE_H

