#include <cstdlib>
#include <iostream>
#ifndef POINT_H
#define POINT_H


using namespace std;

//Class Point represents points in the Cartesian coordinate
class Point
{
public:
double x, y; // coordinates of the point


Point(double xin, double yin){
	x = xin;
	y = yin;
}

};


#endif