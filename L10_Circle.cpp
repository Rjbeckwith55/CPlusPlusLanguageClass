/*
	 FILE:   L10_Circle.cpp
	 AUTHOR: Robert Beckwith
	 DATE:   04/25/2017
	 DESCR:
	 This is the implementation file for the
	 Circle class.
*/

#define _USE_MATH_DEFINES  // enable non-standard mathematical constants
#include <cmath>

// include specification file
#include "L10_Circle.h"

// Object counter declaration and accessor
int Circle::objCounter = 0;
int Circle::getObjCounter() { 
	return objCounter; 
}

// constructors
Circle::Circle() {
	name = new string("");
	diameter = 0;
	centerX = 0;
	centerY = 0;
	objCounter++;
}

Circle::Circle(string n, double d, int x, int y) {
	name = new string(n);
	diameter = d;
	centerX = x;
	centerY = y;
	objCounter++;
}

// destructor
Circle::~Circle() {
	delete name;
}
Circle::Circle(const Circle& inpCirc) {
	name = new string(*inpCirc.name);
	diameter = inpCirc.diameter;
	centerX = inpCirc.centerX;
	centerY = inpCirc.centerY;
	objCounter++;
}


// mutators
void Circle::setName(string n) {
	*name = n;
}

void Circle::setDiameter(double d) {
	diameter = d;
}

void Circle::setCenterX(int x) {
	centerX = x;
}

void Circle::setCenterY(int y) {
	centerY = y;
}

// calculators
double Circle::calcArea() const {
	return M_PI * pow((diameter / 2), 2.0);
}

double Circle::calcPerimeter() const {
	return M_PI * diameter;
}


Circle& Circle::operator = (const Circle & rhs) {
	this->name = new string(*rhs.name);
	this->diameter = rhs.diameter;
	this->centerX = rhs.centerX;
	this->centerY = rhs.centerY;
	return *this;
}
// overloaded insertion operator as friend function
ostream& operator<< (ostream& lhs, const Circle& rhs) {
	lhs << *rhs.name << " diameter = " << fixed << setprecision(2) << rhs.diameter
		<< " area = " << rhs.calcArea() << endl;
	return lhs;
}