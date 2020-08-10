#ifndef __POINT_H
#define __POINT_H

#include <iostream>
#include<stdlib.h>
using namespace std;


class Point
{
public:
	Point(int x = 0, int y = 1);//ctor
	Point(Point & other);//copy ctor
	Point(Point && other); // move ctor
	~Point() = default;//dtor

	void setX(int x);//set x
	void setY(int y);//set y

	int getX()const;//get x
	int getY()const;//get y

	const Point& operator=(const Point& other);
private:

	int m_x;
	int m_y;
};


#endif // !__POINT_H

