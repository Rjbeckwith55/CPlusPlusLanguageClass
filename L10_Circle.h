/*
     FILE:   L10_Circle.h
	 AUTHOR: Robert Beckwith
	 DATE:   04/25/2017
	 DESCR:
	 This is the specification file for the
	 Circle class.
*/

// using declarations for std namespace
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// prevent multiple definitions of Student class
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle 
 {
 private:
	 string* name;
	 double diameter;
	 int centerX;
	 int centerY;
	 static int objCounter;
 public:
	 // constructor
	 Circle();
	 Circle(string, double, int, int);
	 Circle(const Circle&);
	 // destructor
	 ~Circle();
	 // inline accessors
	 string getName() const {return *name;}
	 double getDiameter() const {return diameter;}
	 int getCenterX() const {return centerX;}
	 int getCenterY() const {return centerY;}
	 static int getObjCounter();
	 // mutators
	 void setName(string);
	 void setDiameter(double);
	 void setCenterX(int);
	 void setCenterY(int);
	 // calculators
	 double calcArea() const;
	 double calcPerimeter() const;
	 // overloaded insertion operator as friend function
	 friend ostream& operator<< (ostream&, const Circle&);
	 Circle& Circle::operator = (const Circle & rhs);
	 
 };
#endif