/*
Author: Robert Beckwith
Date: 3/20/17
StockLookUp.cpp
Program #3
CIS 2451
Descr: Program that reads the stock data into parallel arrays and outputs it
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <memory>
using namespace std;

void sortSelect(string * symbol, int size);
int linearSearch(string * symbols, int size, string searchSymbol);

/*Main function to open file, create and manage dynamic arrays, read data from file
into arrays, display sorted trading symbols 3 to a line, prompt user for trading
symbol to search, and display result of trading symbol search with 2 digits
precision for floating point numbers*/
int main() {
	//Declare variables
	fstream inpFile;
	string fileName;
	string searchSymbol;
	int foundIndex;
	int size = 0;

	//Prompt for the file name and open the file
	cout << "Enter the filename: ";
	getline(cin, fileName);
	inpFile.open(fileName, ios::in);

	//Check if the file exists
	if (inpFile) {
		inpFile >> size;

		//Declare dynamic arrays using smart pointers
		unique_ptr<string[]> symbols(new string[size]);
		unique_ptr<string[]> names(new string[size]);
		unique_ptr<int[]> numShares(new int[size]);
		unique_ptr<float[]> prices(new float[size]);

		//Read data into parallel arrays
		int i = 0;
		while (!inpFile.eof()) {
			inpFile >> symbols[i];
			getline(inpFile, names[i], '#');
			inpFile >> numShares[i] >> prices[i];
			//cout << symbols[i] << names[i] << numShares[i] << prices[i] << endl;
			i++;
		}
		//Close the file
		inpFile.close();

		//Create a dynamic array of pointers
		unique_ptr<string[]> symbolsptr(new string[size]);
		for (int count = 0; count < size; count++) {
			symbolsptr[count] = symbols[count];
		}

		//Sort symbols
		sortSelect(symbolsptr.get(), size);

		//Output sorted stocks
		int counter = 0;
		cout << "Available stocks: " << endl;
		cout << endl;
		for (int i = 0; i < size; i++) {
			//Output 3 to a line
			if (counter % 3 == 0)
				cout << endl;
			cout << symbolsptr[i] << ' ';
			counter++;
		}

		cout << endl;
		cout << endl;

		//Prompt for a symbol to search for
		cout << "Enter the symbol: ";
		getline(cin, searchSymbol);
		cout << endl;
		cout << endl;

		//Search the array of pointers for the trading symbol
		foundIndex = linearSearch(symbols.get(), size, searchSymbol);

		//Calculate the total value of all the shares
		float value = 0;
		value = prices[foundIndex] * numShares[foundIndex];

		//Format output
		cout << setprecision(2);
		cout << fixed;
		int width = 30;

		//Output all the data for the requested trading symbol
		cout << setw(width) << left << "Company Name: " << right << setw(width) << names[foundIndex] << endl;;
		cout << setw(width) << left << "Number of Shares: " << right << setw(width) << numShares[foundIndex] << endl;;
		cout << setw(width) << left << "Current Price (per share): " << right << setw(width) << prices[foundIndex] << endl;;
		cout << setw(width) << left << "Current Value: " << right << setw(width) << value << endl;


	}
	//Exit if the file does not exist
	else {
		cout << "Error opening file" << endl;
		exit(-1);
	}

	return 0;
}

//Searches for the index of the stock symbol
int linearSearch(string * symbols, int size, string searchSymbol) {
	string word;
	word = searchSymbol;

	//Convert the searched string to uppercase
	for (int j = 0; j < word.length(); j++) {
		searchSymbol[j] = toupper(searchSymbol[j]);
	}

	//Search for the symbol
	for (int i = 0; i < size; i++) {
		if (symbols[i] == searchSymbol)
			return i;
	}

	return -1;

}

//Sorts the array of stock symbols
void sortSelect(string * symbols, int size) {
	int startScan, minIndex;
	string minElem;
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minElem = symbols[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if ((symbols[index]) < minElem)
			{
				minElem = symbols[index];
				minIndex = index;
			}
		}
		symbols[minIndex] = symbols[startScan];
		symbols[startScan] = minElem;
	}

}
