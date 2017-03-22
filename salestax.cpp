/*
Author:     Robert Beckwith
File:       salestax.cpp
Date:       1/30/16
Class:      CIS 2541
Assignment: Lab #1
Descr: Lab to calculate and display the cost of a purchased item*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	//Named constants to hold tax rates
	const float COUNTY_SALES_TAX = .04F;
	const double STATE_SALES_TAX = .02;
	//cout << sizeof(COUNTY_SALES_TAX) << endl;
	//cout << sizeof(STATE_SALES_TAX) << endl;
	//Variable delarations
	float cost = 95.0;
	float stateTax;
	float countyTax;
	float total;
	string storeName;
	char isExpensive;

	//Get cost if the item
	cout << "Input the cost of the item: ";
	cin >> cost;
	cin.ignore();
	cout << "Where was the item purchased?: ";
	//cin >> storeName; //stops at first whitespace
	getline(cin, storeName);
	cout << "Was this expensive? (Y/N) ";
	cin.get(isExpensive);

	//Compute tax values
	cout << "Purchase was made at: " << storeName << endl;
	stateTax = STATE_SALES_TAX*cost;
	countyTax = cost*static_cast<float>(COUNTY_SALES_TAX);
	total = stateTax + countyTax + cost;

	cout << setprecision(2);
	cout << showpoint;
	cout << fixed; //digits of precision after the decimal point
	
	
	
	//Output
	cout << setw(20) <<  "Purchase Price: $" << setw(10) << cost << endl;
	cout << setw(20) << "The state tax is: $" << setw(10) << stateTax <<  endl;
	cout << setw(20) << "The county tax is: $" << setw(10) << countyTax << endl;
	cout << setw(20) << "The total cost is: $" << setw(10) << total << endl;
	cout << endl << "This item is expensive: " << isExpensive << endl;
	return 0;
}
/* OUTPUT
Purchase Price: $95
The state tax is: $1.9
The county tax is: $3.8
The total cost is: $100.7
Press any key to continue . . .
*/