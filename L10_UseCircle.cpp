/*
     FILE:   L10_UseCircle.cpp
	 AUTHOR: Robert Beckwith
	 DATE:   04/25/2017
	 DESCR:
	 This is a client file for the Circle class.  Three Circles objects are  
	 created using various constructors.  Circle object properties are then  
	 modified using mutator methods.  Finally, Circle objects are displayed 
	 using the overloaded insertion operator.
*/

// specification file
#include "L10_Circle.h"

int main() {
	// output number of circle objects
	cout << "Number of circle objects before: " << Circle::getObjCounter() << endl;
	// create circle objects
	Circle c1("c1", 4.0, 1, 1), c2(c1), c3;
	// reset c2 properties
	c2.setName("c2");
	c2.setDiameter(6.0);
	// assign c2 properties to c3
	c3 = c2;
	// reset c3 properties
	c3.setName("c3");
	c3.setDiameter(8.0);
	// display circles
	cout << "**Circles***" << endl;
	cout << c1 << c2 << c3;
	// output number of circle objects
	cout << "Number of circle objects after: " << Circle::getObjCounter() << endl;
	return 0;
}
/* SAMPLE OUTPUT
Number of circle objects before: 0
**Circles***
c1 diameter = 4.00 area = 12.57
c2 diameter = 6.00 area = 28.27
c3 diameter = 8.00 area = 50.27
Number of circle objects after: 3
Press any key to continue . . .*/