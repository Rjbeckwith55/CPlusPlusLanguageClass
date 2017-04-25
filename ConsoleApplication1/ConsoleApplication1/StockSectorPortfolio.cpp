/*Robert Beckwith
StockSectorPortfolio.cpp
4/23/17
CIS 2541
Program #4
Description: Reads data from a file and creates and displays a stock portfolio*/

#include "Stock.h"

int ReadStkData(Stock stks[], int maxSize);
void SortStks(Stock stks[], int size);
void CalculatePortfolio(Stock stks[], int size);

void main() {
	const int maxSize = 25;
	Stock stocks[maxSize];
	int size;
	size = ReadStkData(stocks, maxSize);
	SortStks(stocks, size);
	CalculatePortfolio(stocks, size);

}

int ReadStkData(Stock stks[], int maxSize) {
	string fileName;
	string symbol, name;
	int sectorNum;
	int numShares;
	float purchasePrice, currentPrice;
	fstream inpFile;

	// Get the filename and open it for reading
	cout << "Please enter a filename to read from: ";
	getline(cin, fileName);
	//fileName = "D:\\Users\\rjbec_000\\Documents\\P4_stkPort.txt";
	inpFile.open(fileName, ios::in);

	// Loop through reading the data from the file into Stock object arrays.
	int i = 0;
	if (inpFile) {


		while (!inpFile.eof() && i < maxSize) {
			inpFile >> symbol;
			getline(inpFile, name, '#');
			inpFile >> sectorNum >> numShares >> purchasePrice >> currentPrice;
			stks[i].setSymbol(symbol);
			stks[i].setName(name);
			stks[i].setSector(static_cast<Stock::sector>(sectorNum));
			stks[i].setNumShares(numShares);
			stks[i].setPurchasePrice(purchasePrice);
			stks[i].setCurrentPrice(currentPrice);
			//cout << symbol << name << sectorNum << numShares << purchasePrice << currentPrice << endl;
			i++;
		}
	}
	else {
		cout << "File does not exist" << endl;
		exit(-1);
	}
	inpFile.close();
	return i;
}

void SortStks(Stock stks[], int size) {
	Stock swap;
	for (int c = 0; c < (size - 1); c++)
	{
		for (int d = 0; d < size - c - 1; d++)
		{
			if (stks[d].getSector() > stks[d + 1].getSector()) /* For decreasing order use < */
			{
				swap = stks[d];
				stks[d] = stks[d + 1];
				stks[d + 1] = swap;
			}
		}
	}
}
void CalculatePortfolio(Stock stks[], int size) {
	fstream outFile;
	string fileName;
	int w1 = 35;
	int w2 = 50;
	int w3 = 20;
	int w4 = 50;
	int w5 = 10;
	int x = 0;
	float totalGain = 0;
	Stock stk;
	// Get the filename and open it for writing
	cout << "Please enter a filename to write to: ";
	getline(cin, fileName);
	outFile.open(fileName, ios::out);
	outFile << "Prepared Portfolio Analysis Summarized by Sector" << endl;
	outFile << "Long Term Capital Gain Tax Rate = " << Stock::TAX_RATE << endl;
	cout << endl;
	outFile.precision(2);
	outFile.setf(ios::fixed);
	for (int i = 0; i < 5; i++) {
		outFile << left << setw(w5) << "Symbol" << setw(w1) << "Company" << setw(w2) << right << "Status" << endl;
		outFile << left << setw(w5) << "======" << setw(w1) << "=======" << setw(w2) << right << "======" << endl;
		totalGain = 0;
		while (x < size) {
			outFile << left << setw(w5) << stks[x].getSymbol() << setw(w1) << stks[x].getName();
			switch (stk.getCurrStatus(stks[x])) {
			case 0:
				outFile << setw(w2) << right << "GAIN" << endl;
				break;
			case 1:
				outFile << setw(w2) << right << "LOSS" << endl;
				break;
			case 2:
				outFile << setw(w2) << right << "BREAKEVEN" << endl;
				break;
			}
			if (stks[x].getCurrStatus(stks[x]) == 0)
				totalGain += stks[x].getGainAmt(stks[x]);
			if (stks[x].getSector() != stks[x + 1].getSector()) {
				x++;
				break;
			}

			x++;
		}


		outFile << setw(w4) << right << "Summary for sector: ";
		switch (stks[x - 1].getSector())
		{
		case 10:
			outFile << setw(w3) << right << "TECHNOLOGY" << endl;
			break;
		case 20:
			outFile << setw(w3) << right << "HEALTH" << endl;
			break;
		case 30:
			outFile << setw(w3) << right << "FINANCIAL" << endl;
			break;
		case 40:
			outFile << setw(w3) << right << "CONSUMER GOODS" << endl;
			break;
		case 50:
			outFile << setw(w3) << right << "UTILITIES" << endl;
			break;
		}
		outFile << setw(w4) << right << "Gain amount: " << setw(w3) << totalGain << endl;
		outFile << setw(w4) << right  << "Tax on Gain: " << setw(w3) << stk.getTaxGainAmt(totalGain) << endl;
	}

	outFile.close();
	cout << "The report has been created" << endl;
}