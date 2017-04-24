/*Robert Beckwith
StockSectorPortfolio.cpp
4/23/17
CIS 2541 
Program #4
Description: Reads data from a file and creates and displays a stock portfolio*/

#include "Stock.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void main() {

}

int ReadStkData(Stock stks[], int maxSize) {
	string fileName;
	string symbol, name;
	int sector;
	int numShares;
	float purchasePrice, currentPrice;
	fstream inpFile;
	cout << "Please enter a filename to read from";
	getline(cin, fileName);
	inpFile.open(fileName, ios::in);
	
	int i = 0;
	while (!inpFile.eof() && i < maxSize) {
		inpFile >> symbol;
		getline(inpFile, name, '#');
		inpFile >> sector >> numShares >> purchasePrice >> currentPrice;
		Stock stks[i](symbol, name, sector, numShares, purchasePrice, currentPrice);
		i++;
	}
	inpFile.close();
	return i;
}