#include "Point.h"

Point::Point(int x, int y)
{
	setX(x);
	setY(y);
}

Point::Point(Point & other) :Point(other.m_x, other.m_y)
{
}

Point::Point(Point && other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}


void Point::setX(int x)
{
	m_x = x;
}

void Point::setY(int y)
{
	m_y = y;
}

int Point::getX() const
{
	return m_x;
}

int Point::getY() const
{
	return m_y;
}

const Point& Point::operator=(const Point & other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	return *this;
}
