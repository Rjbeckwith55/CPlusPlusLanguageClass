/*Robert Beckwith
Stock.cpp
4/23/17
CIS 2541
Program #4
Description: Stock class definition --> implementation file*/
#include "Stock.h"


Stock::Stock() {
	cout << "\n\tDefault Constructor called.\n";
}
Stock::~Stock() {
	cout << "\n\tDestructor called.\n";
}
Stock::Stock(string s, string n, sector sec, int num, float p, float cp) {
	symbol = s;
	name = n;
	numShares = num;
	purchasePrice = p;
	currentPrice = cp;
}
enum getCurrStatus { GAIN, LOSS, BREAKEVEN };

float Stock::getGainAmt() {
	int gain;
	if (1 == GAIN) {
		gain = numShares*(currentPrice - purchasePrice);
		return gain;
	}
	else
		return 0.0;
}
float Stock::getTaxGainAmt() {
	int gainAmt;
	gainAmt = getGainAmt();
	return gainAmt + (gainAmt * .15);
}