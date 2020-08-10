#include "Stack.h"

Stack::Stack()
{
	m_top = nullptr;
}

Stack::Stack(Stack & other)
{
	m_top = other.m_top;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	Node* tmp;
	while (m_top)
	{
		tmp = m_top;
		m_top = m_top->getNext();
		delete tmp;
	}
}

bool Stack::IsEmpty()
{
	return (m_top == nullptr);
}

void Stack::Push(Point& point)
{
	Node* newNode = new Node(point);
	newNode->setNext(m_top);
	m_top = newNode;
}

Point& Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Error:STACK UNDERFLOW" << endl;
		exit(1);
	};

	Node* tmp = m_top;
	m_top = m_top->getNext();
	return tmp->getPoint();
}

const Point& Stack::Top()const
{
	return m_top->getPoint();
}
