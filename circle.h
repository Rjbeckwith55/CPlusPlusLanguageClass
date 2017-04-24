/*
Robert Beckwith
circle.h
4/19/17
CIS 2541
Lab #9 Circle class
Descr: Header file to define the circle class
*/
#include <iostream>
using namespace std;

//Prevents multiple class declarations
#ifndef circle_H
#define cricle_H

//Declare the Circle class
class Circle {
private:
	double radius;
	double pi;
public:
	//default contructor
	Circle();
	//parameterized contructor
	Circle(double);
	void setRadius(double r);
	double getRadius() {return radius;}
	double getArea();
	double getDiameter();
	double getCircumference();
};

#endif
