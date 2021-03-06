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
	for (int i = 0; i < size; i++) {


		// Loop through the data of that sector and output it to the file
		if (i == 0 || stks[i].getSector() != stks[i - 1].getSector()) {
			// Output the header for the column for each sector to the file
			outFile << left << setw(w5) << "Symbol" << setw(w1) << "Company" << setw(w2) << right << "Status" << endl;
			outFile << left << setw(w5) << "======" << setw(w1) << "=======" << setw(w2) << right << "======" << endl;
			// Reset the gain calculation after every sector is looped through
			totalGain = 0;
		}
		outFile << left << setw(w5) << stks[i].getSymbol() << setw(w1) << stks[i].getName();

		// Switch statement to output the enumerated datatype for satus
		switch (stk.getCurrStatus(stks[i])) {
		case Stock::GAIN:
			outFile << setw(w2) << right << "GAIN" << endl;
			break;
		case Stock::LOSS:
			outFile << setw(w2) << right << "LOSS" << endl;
			break;
		case Stock::BREAKEVEN:
			outFile << setw(w2) << right << "BREAKEVEN" << endl;
			break;
		}
		// If the stock shows a gain add it to the total for this sector
		if (stks[i].getCurrStatus(stks[i]) == Stock::GAIN) 
			totalGain += stks[i].getGainAmt(stks[i]);
		// If the next stock is not part of this sector break out of the loop and move onto the next sector


		if (stks[i + 1].getSector() != stks[i].getSector()) {
			outFile << setw(w4) << right << "Summary for sector: ";

			// Switch statement to output the enumerated datatype for sector
			switch (stks[i].getSector())
			{
			case Stock::TECHNOLOGY:
				outFile << setw(w3) << right << "TECHNOLOGY" << endl;
				break;
			case Stock::HEALTH:
				outFile << setw(w3) << right << "HEALTH" << endl;
				break;
			case Stock::FINANCIAL:
				outFile << setw(w3) << right << "FINANCIAL" << endl;
				break;
			case Stock::CONSUMER_GOODS:
				outFile << setw(w3) << right << "CONSUMER GOODS" << endl;
				break;
			case Stock::UTILITIES:
				outFile << setw(w3) << right << "UTILITIES" << endl;
				break;
			}
			// Output the gain and the tax on the gain to the file.
			outFile << setw(w4) << right << "Gain amount: " << setw(w3) << totalGain << endl;
			outFile << setw(w4) << right << "Tax on Gain: " << setw(w3) << stk.getTaxGainAmt(totalGain) << endl;
		}
	}

	outFile.close();
	cout << "The report has been created." << endl;
}
/* SAMPLE OUTPUT
Please enter a filename to read from: D:\Users\rjbec_000\Documents\CPlusPlusLanguageClass\P4_stkPort.txt
Please enter a filename to write to: output.txt
The report has been created.
Press any key to continue . . .

*****output.txt*****

Prepared Portfolio Analysis Summarized by Sector
Long Term Capital Gain Tax Rate = 0.15
Symbol    Company                                                                        Status
======    =======                                                                        ======
CA         CA Inc                                                                     BREAKEVEN
SYMC       Symantec Corp                                                                   LOSS
TWTR       Twitter Inc                                                                     GAIN
                              Summary for sector:           TECHNOLOGY
                                     Gain amount:                29.40
                                     Tax on Gain:                 4.41
Symbol    Company                                                                        Status
======    =======                                                                        ======
JNJ        Johnson & Johnson                                                               GAIN
LLY        Eli Lilly and Company                                                           GAIN
RPTP       Raptor Pharmaceutical Corp                                                 BREAKEVEN
                              Summary for sector:               HEALTH
                                     Gain amount:                23.81
                                     Tax on Gain:                 3.57
Symbol    Company                                                                        Status
======    =======                                                                        ======
BAC        Bank of America Corp                                                            LOSS
WFC        Wells Fargo & Co                                                           BREAKEVEN
V          Visa                                                                            LOSS
                              Summary for sector:            FINANCIAL
                                     Gain amount:                 0.00
                                     Tax on Gain:                 0.00
Symbol    Company                                                                        Status
======    =======                                                                        ======
RDEN       Elizabeth Arden Inc                                                             LOSS
AVP        Avon Products Inc                                                          BREAKEVEN
COH        Coach Inc                                                                       GAIN
                              Summary for sector:       CONSUMER GOODS
                                     Gain amount:                35.20
                                     Tax on Gain:                 5.28
Symbol    Company                                                                        Status
======    =======                                                                        ======
EIX        Edison International                                                       BREAKEVEN
HE         Hawaiian Electric Industries Inc                                                GAIN
POR        Portland General Electric                                                       LOSS
                              Summary for sector:            UTILITIES
                                     Gain amount:               156.20
                                     Tax on Gain:                23.43

*/
