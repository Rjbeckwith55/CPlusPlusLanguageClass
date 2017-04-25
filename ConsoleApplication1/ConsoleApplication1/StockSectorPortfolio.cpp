/*Robert Beckwith
StockSectorPortfolio.cpp
4/23/17
CIS 2541 
Program #4
Description: Reads data from a file and creates and displays a stock portfolio*/

#include "Stock.h"


void main() {
	const int maxSize = 25;
	Stock stocks[maxSize];
	int numStocks;
	numStocks = ReadStkData(stocks, maxSize);

}

int ReadStkData(Stock stks[], int maxSize) {
	string fileName;
	string symbol, name;
	int sector;
	int numShares;
	float purchasePrice, currentPrice;
	fstream inpFile;

	// Get the filename and open it for reading
	cout << "Please enter a filename to read from: ";
	getline(cin, fileName);
	inpFile.open(fileName, ios::in);
	
	// Loop through reading the data from the file into Stock object arrays.
	int i = 0;
	while (!inpFile.eof() && i < maxSize) {
		inpFile >> symbol;
		getline(inpFile, name, '#');
		inpFile >> sector >> numShares >> purchasePrice >> currentPrice;
		stks[i].setSymbol(symbol);
		stks[i].setName(name);
		stks[i].setSector(static_cast<Stock::sector>(sector));
		stks[i].setNumShares(numShares);
		stks[i].setPurchasePrice(purchasePrice);
		stks[i].setCurrentPrice(currentPrice);
		cout << symbol, name, sector, numShares, purchasePrice, currentPrice;
		i++;
	}
	inpFile.close();
	return i;
}