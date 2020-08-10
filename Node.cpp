#include "Node.h"

Node::Node(Point &  point)
{
	m_point = point;
	m_next = nullptr;
}

Node::Node(Point & point, Node * next)
{
	m_point = point;
	m_next = next;
}

Node::Node(Node & other) :Node(other.m_point, other.m_next)
{
}

void Node::setNext(Node * next)
{
	m_next = next;
}

Node * Node::getNext() const
{
	return m_next;
}

Point & Node::getPoint() 
{
	return m_point;
}

