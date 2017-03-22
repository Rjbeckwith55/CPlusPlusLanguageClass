/*Author: Robert Beckwith
Date: 2/27/16
Class: CIS 2541
Assignment: #2
Descr: Read stocks from a file and output them with the caluclated total profit from the stocks.

*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Function delcaration
float profit(int numShares, float salesPrice, float salesCom, float purchasePrice, float purchaseCom);
bool openFile(fstream& file, string fileName);


int main() {
	//Variable declarations
	int numShares = 0;
	string symbol;
	float Profit = 0;
	float totalProfit = 0;
	int  totalShares = 0;
	float salesPrice = 0, salesCom = 0, purchasePrice = 0, purchaseCom = 0;
	
	//initialize the file
	fstream file;
	string fileName;
	cout << "Input the name of the stock file you would like to read from: ";
	getline(cin, fileName);
	//fileName = "C:\\Users\\rjbec\\OneDrive for Business\\P2_stocks.txt";

	//Bool to hold if the file exists
	bool exists = openFile(file, fileName);
	
	if (exists) {
		cout << "Reading the file..." << endl;

		//Format the output
		cout << setprecision(2);
		cout << fixed;
		
		//Output the header
		cout << left;
		cout << setw(12) << "STOCK" << setw(4) << right << "SHARES" << setw(12) << right << "P Price" << setw(12) << right << "S Price" << setw(15) << right << "Profit(Loss)" << endl;
		cout << left;
		cout << setw(12) << "_____" << setw(4) << right << "______" << setw(12) << "_______" << setw(12) << "_______" << setw(15) << "____________" << endl;
		
		while(!file.eof()) {
			//Read contents of the file into variables
			file >> symbol >> numShares >> purchasePrice >> purchaseCom >> salesPrice>> salesCom;

			//Call the profit function to calculate the profit or loss
			Profit = profit(numShares, salesPrice, salesCom, purchasePrice, purchaseCom);
			//Calculate total shares and total profit
			totalProfit = totalProfit + Profit;
			totalShares = numShares + totalShares;
			//Output the stocks
			cout << setw(12) << left << symbol << setw(6) << right << numShares << setw(12) << right << purchasePrice << setw(12) << salesPrice << setw(15) << Profit << endl;
			
		}
		cout << "Total profit (loss) for " << totalShares << " shares = $" << totalProfit << endl;


			
	}
	//Error if the file path does not exist
	else {
		cout << "ERROR opening file" << endl;
		exit(-1);
	}

	//close the file
	file.close();
	return 0;
}

//Check if valid file
bool openFile(fstream& file, string fileName){
	//open the file
	file.open(fileName, ios::in);
	
	if (!file)
	{
		
		return false;
	}
	else
		return true;

}

//Function to calculate profit
float profit(int numShares, float salesPrice, float salesCom, float purchasePrice, float purchaseCom) {
	float profit;
	profit = ((numShares*salesPrice) - salesCom) - ((numShares*purchasePrice) + purchaseCom);
	return profit;
}
/*
Input the name of the stock file you would like to read from : C:\Users\rjbec\OneDrive for Business\P2_stocks.txt
Reading the file...
STOCK       SHARES     P Price     S Price   Profit(Loss)
_____       ______     _______     _______   ____________
AAPL            23      102.30       96.25 - 157.05
GE              15       23.00       28.87          70.15
MSFT            30       58.50       52.06 - 213.10
GOOG            10      540.20      695.03        1528.40
Total profit(loss) for 78 shares = $1228.40
Press any key to continue . . .*/
