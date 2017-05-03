/*
FILE:   L11_Sphere.h
AUTHOR: Robert Beckwith
DATE:   5/2/17
DESCR:
This is the definition of the base Sphere class.
*/

#ifndef SPHERE_H
#define SPHERE_H

#include "L11_Circle.h"
class Sphere : public Circle {
public:
	Sphere() :Circle() {}
	Sphere(double r) :Circle(r) {}
	double getArea() const { return 4 * M_PI*pow((radius), 2.0); }
	double getVolume() const { return M_PI*(pow((radius), 3.0))*(4.0 / 3.0); }
};

#endif 
/*SAMPLE OUTPUT
Enter a radius...
Radius: 5.25

Here are the Circle's properties:
Radius: 5.25
Area: 86.5901

Here are the Sphere's properties:
Radius: 5.25
Area: 346.361
Volume: 606.131
Press any key to continue . . .
*/
