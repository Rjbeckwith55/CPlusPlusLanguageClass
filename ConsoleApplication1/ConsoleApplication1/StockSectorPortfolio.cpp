/*Robert Beckwith
StockSectorPortfolio.cpp
4/23/17
CIS 2541
Program #4
Description: Reads data from a file and creates and displays a stock portfolio*/

#include "Stock.h"

// Function prototypes
int ReadStkData(Stock stks[], int maxSize);
void SortStks(Stock stks[], int size);
void CalculatePortfolio(Stock stks[], int size);

// Stores size of the array and calls the other functions
void main() {
	const int maxSize = 25;
	Stock stocks[maxSize];
	int size;
	size = ReadStkData(stocks, maxSize);
	SortStks(stocks, size);
	CalculatePortfolio(stocks, size);
}

// Function that reads the stock data from the file into the stock object array
// and returns the number of elements read. 
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

	// Loop through reading the data from the file into the stock object array.
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
	//Exit if the file does not exist
	else {
		cout << "File does not exist" << endl;
		exit(-1);
	}
	inpFile.close();
	// Returns number of elements read into the array
	return i;
}

// Sorts the Stock object array by the sector it is in (Bubble sort)
void SortStks(Stock stks[], int size) {
	Stock swap;
	for (int c = 0; c < (size - 1); c++)
	{
		for (int d = 0; d < size - c - 1; d++)
		{
			if (stks[d].getSector() > stks[d + 1].getSector()) // For decreasing order use <
			{
				swap = stks[d];
				stks[d] = stks[d + 1];
				stks[d + 1] = swap;
			}
		}
	}
}

//Caculate the portfolio and output it to the output file that is named by the user
void CalculatePortfolio(Stock stks[], int size) {
	fstream outFile;
	string fileName;
	int x = 0;
	float totalGain = 0;
	Stock stk;

	// Variables for setw()
	int w1 = 35, w2 = 50, w3 = 20, w4 = 50, w5 = 10;
	
	// Get the filename and open it for writing
	cout << "Please enter a filename to write to: ";
	getline(cin, fileName);
	outFile.open(fileName, ios::out);

	// Output the file 
	outFile << "Prepared Portfolio Analysis Summarized by Sector" << endl;
	outFile << "Long Term Capital Gain Tax Rate = " << Stock::TAX_RATE << endl;
	cout << endl;

	//Format the output file decimal places
	outFile.precision(2);
	outFile.setf(ios::fixed);

	for (int i = 0; i < 5; i++) { // 5 = number of sectors
		// Output the header for the column for each sector to the file
		outFile << left << setw(w5) << "Symbol" << setw(w1) << "Company" << setw(w2) << right << "Status" << endl;
		outFile << left << setw(w5) << "======" << setw(w1) << "=======" << setw(w2) << right << "======" << endl;
		// Reset the gain calculation after every sector is looped through
		totalGain = 0;
		
		// Loop through the data of that sector and output it to the file
		while (x < size) {
			outFile << left << setw(w5) << stks[x].getSymbol() << setw(w1) << stks[x].getName();

			// Switch statement to output the enumerated datatype for satus
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
			// If the stock shows a gain add it to the total for this sector
			if (stks[x].getCurrStatus(stks[x]) == 0) // 0 is enumerated for GAIN
				totalGain += stks[x].getGainAmt(stks[x]);
			// If the next stock is not part of this sector break out of the loop and move onto the next sector
			if (stks[x].getSector() != stks[x + 1].getSector()) {
				x++;
				break;
			}

			x++;
		}


		outFile << setw(w4) << right << "Summary for sector: ";

		// Switch statement to output the enumerated datatype for sector
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
		// Output the gain and the tax on the gain to the file.
		outFile << setw(w4) << right << "Gain amount: " << setw(w3) << totalGain << endl;
		outFile << setw(w4) << right  << "Tax on Gain: " << setw(w3) << stk.getTaxGainAmt(totalGain) << endl;
	}

	outFile.close();
	cout << "The report has been created." << endl;
}