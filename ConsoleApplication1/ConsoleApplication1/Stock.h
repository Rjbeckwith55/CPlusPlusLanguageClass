/*Robert Beckwith
Stock.h
4/23/17
CIS 2541
Program #4
Description: Stock class declaration --> specification file*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Prevent multiple class delcarations 
#ifndef STUDENT_H
#define STUDENT_H


class Stock {
private:
	string symbol;
	string name;
	enum sector { TECHNOLOGY = 10, HEALTH = 20, FINANCIAL = 30, CONSUMER_GOODS = 40, UTILITIES = 50 };
	int numShares;
	float purchasePrice;
	float currentPrice;
public:
	Stock();
	Stock(string, string, sector, int, float, float);
	~Stock();
	
	sector getSector();
	void setSector(sector sec);
	// Mutators
	void setSymbol(string s) { symbol = s; }
	void setName(string n) { name = n; }
	void setNumShares(int num) { numShares = num; }
	void setPurchasePrice(float p) { purchasePrice = p; }
	void setCurrentPrice(float cp) { currentPrice = cp; }

	float getCurrValue() { return numShares*currentPrice; }
	enum getCurrStatus { GAIN, LOSS, BREAKEVEN };
	float getGainAmt();
	float getTaxGainAmt();
	friend int ReadStkData(Stock stks[], int maxSize);
};
#endif