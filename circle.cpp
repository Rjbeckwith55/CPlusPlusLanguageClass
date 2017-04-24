/*
Robert Beckwith
circle.cpp
4/19/17
CIS 2541
Lab #9 Circle class
Descr: Class constructors set the values of the radius that is read in as user input
*/
#include "circle.h"

//Default constructor
Circle::Circle() {
	radius = 0;
	pi = 3.14159;
}

//Parameterized constructor
Circle::Circle(double r) {
	radius = r;
	pi = 3.14159;
}

void Circle::setRadius(double r){
	radius = r;
}

double Circle::getArea() {
	return pi * radius * radius;
}
double Circle::getDiameter() {
	return radius * 2;
}
double Circle::getCircumference() {
	return 2 * pi * radius;
}

int main() {
	Circle circ1;
	double r;
	//Get the radius from the user
	cout << "Enter the radius of the circle: ";
	cin >> r;
	circ1.setRadius(r);

	//Output the measurements of the circle
	cout << "The radius of the circle is: "<< circ1.getRadius() << endl;
	cout << "The area of the circle is: " << circ1.getArea() << endl;
	cout << "The diameter of the circle is: " << circ1.getDiameter() << endl;
	cout << "The circumference of the circle is: " << circ1.getCircumference() << endl;


	return 0;
}
