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

/*Main function to open file, create and manage dynamic arrays, read data from file
into arrays, display sorted trading symbols 3 to a line, prompt user for trading
symbol to search, and display result of trading symbol search with 2 digits
precision for floating point numbers*/
void sortSelect(string * symbol, int size);

int main() {
	fstream inpFile;
	string fileName;
	string searchSymbol;

	//Initialize variables to 0
	int size = 0;
	//string *symbols = nullptr;
	//string *names = nullptr;
	//int *numShares = nullptr;
	//float *prices = nullptr;

	//Prompt for the file name and open the file
	cout << "Enter the filename: ";
	getline(cin, fileName);
	//fileName = "C:\\Users\\rjbec\\Desktop\\P3_stkPort.txt";
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
			getline(inpFile,names[i], '#');
			inpFile >> numShares[i] >> prices[i];
			cout << symbols[i] << names[i] << numShares[i] << prices[i] << endl;
			i++;
		}
		sortSelect(symbols.get(), size);

		//Output sorted stocks
		int counter = 0;
		cout << "Available stocks: " << endl;
		cout << endl;
		for (int i = 0; i < size; i++) {
			if (counter % 3 == 0)
				cout << endl;
			cout << symbols[i]<<' ';
			counter++;
		}
		cout << "Enter the symbol: ";
		getline(cin,searchSymbol)

	}
	else {
		cout << "Error opening file" << endl;
		exit(-1);
	}
	cout << "File closed" << endl;
	inpFile.close();
	return 0;
}

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
