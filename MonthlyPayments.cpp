/*
Author: Robert Beckwith
Date: 2/6/16
File: MonthlyPayments.cpp
Class: CIS 2541
Assignment: Program #1
Descr: Calculate the monthly payments on a loan*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
	//Declare variables
	float annualRate, loanAmount, monthlyRate = 0, monthlyPay = 0, interestPaid = 0, amountPaid = 0;
	int numPay;
	
	//Get input from the user
	cout << "Input loan amount: $";
	cin >> loanAmount;
	cout << "Input annual interest rate: ";
	cin >> annualRate;
	cout << "Input number of payments: ";
	cin >> numPay;
	
	//Format the output
	cout << setprecision(2);
	cout << fixed;
	
	//Check for valid input
	if (annualRate >= 0 && loanAmount >= 0 && numPay >= 0) {
		


		//Check for zero
		if (annualRate != 0 && loanAmount != 0 && numPay != 0) {
			//Calculate
			monthlyRate = annualRate / 12;
			monthlyPay = (monthlyRate*.01)*pow(1 + (monthlyRate*.01), numPay) / (pow(1 + (monthlyRate*.01), numPay) - 1)*loanAmount;
			amountPaid = monthlyPay * 36;
			interestPaid = amountPaid - loanAmount;
		}
		else
		{
			monthlyPay = 0;
			amountPaid = 0;
			interestPaid = 0;
		}



		//Output all the values
		cout << setw(25) << left << "Loan Amount: " <<"$"<< right << setw(10) << loanAmount << endl;
		cout << setw(25) << left << "Monthly Interest Rate:" << right << setw(10) << monthlyRate << "%" << endl;
		cout << setw(25) << left << "Number of Payments: " << right << setw(11) << numPay << endl;
		cout << setw(25) << left << "Monthly Payment: " << "$" << right << setw(10) << monthlyPay << endl;
		cout << setw(25) << left << "Amount Paid Back: " << "$" << right << setw(10) << amountPaid << endl;
		cout << setw(25) << left << "Interest Paid: " << "$" << right << setw(10) << interestPaid << endl;
	}
	else
		cout << "ERROR! Number must be greater than zero." << endl;
	return 0;
}
/*OUTPUT
Input loan amount: $10000
Input annual interest rate: 12
Input number of payments: 36
Loan Amount:             $  10000.00
Monthly Interest Rate:         1.00%
Number of Payments:               36
Monthly Payment:         $    332.14
Amount Paid Back:        $  11957.15
Interest Paid:           $   1957.15
Press any key to continue . . .*/