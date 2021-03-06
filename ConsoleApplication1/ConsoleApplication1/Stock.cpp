/*Robert Beckwith
Stock.cpp
4/23/17
CIS 2541
Program #4
Description: Stock class definition --> implementation file*/
#include "Stock.h"


Stock::Stock() {
}
Stock::~Stock() {
}
Stock::Stock(string s, string n, sector sec, int num, float p, float cp) {
	symbol = s;
	name = n;
	sect = sec;
	numShares = num;
	purchasePrice = p;
	currentPrice = cp;
}
const float Stock::TAX_RATE = static_cast<float>(.15) ;

Stock::Status Stock::getCurrStatus(Stock stk) {
	Status stat;
	if (stk.currentPrice - .05 > stk.purchasePrice) {
		stat = GAIN;
		return stat;
	}
	else if (stk.currentPrice + .05 < stk.purchasePrice)
	{
		stat = LOSS;
		return stat;
	}
	else
	{
		stat = BREAKEVEN;
		return stat;
	}

}

// Calculates the amount gain by calculating the difference between purchasePrice and currentPrice
float Stock::getGainAmt(Stock stk) {
	if (stk.numShares*(stk.currentPrice - stk.purchasePrice) != 0)
		return stk.numShares*(stk.currentPrice - stk.purchasePrice);
	else
		return 0.0;
}
float Stock::getTaxGainAmt(float gainAmt) {
	return (gainAmt * Stock::TAX_RATE);
}
