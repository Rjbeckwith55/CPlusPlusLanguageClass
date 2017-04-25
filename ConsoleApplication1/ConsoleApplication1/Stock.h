/*Robert Beckwith
Stock.h
4/23/17
CIS 2541
Program #4
Description: Stock class declaration --> specification file*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Prevent multiple class delcarations 
#ifndef STUDENT_H
#define STUDENT_H


class Stock {
public:
	enum sector { TECHNOLOGY = 10, HEALTH = 20, FINANCIAL = 30, CONSUMER_GOODS = 40, UTILITIES = 50 };
private:
	string symbol;
	string name;
	sector sect;
	int numShares;
	float purchasePrice;
	float currentPrice;
public:
	
	Stock();
	Stock(string, string, sector, int, float, float);
	~Stock();
	static const float TAX_RATE;

	enum Status { GAIN, LOSS, BREAKEVEN };
	Status getCurrStatus(Stock stk);

	//Accessors
	string getSymbol() { return symbol; }
	string getName() { return name; }
	sector getSector() { return sect; }
	int getNumShares() { return numShares; }
	float getPurchasePrice() { return purchasePrice; }
	float getCurrentPrice() { return currentPrice; }
	static float getTaxRate() {return TAX_RATE;}

	// Mutators
	void setSymbol(string s) { symbol = s; }
	void setName(string n) { name = n; }
	void setSector(sector sec) { sect = sec; }
	void setNumShares(int num) { numShares = num; }
	void setPurchasePrice(float p) { purchasePrice = p; }
	void setCurrentPrice(float cp) { currentPrice = cp; }

	float getCurrValue(Stock stk) { return stk.numShares*stk.currentPrice; }
	float getGainAmt(Stock stk);
	float getTaxGainAmt(float gainAmt);
	friend int ReadStkData(Stock stks[], int maxSize);
};
#endif