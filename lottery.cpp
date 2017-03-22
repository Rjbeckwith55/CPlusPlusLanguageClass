/*Author: Robert Beckwith
File: lottery.cpp
Date: 3/1/17
Class: CIS 2541
Assignment: Lab #5 Functions and Arrays
Descr: Generate lottery numbers and have the user pick their 5 and check how many they got correct
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

//Function protocol
void generateNumbers(int[], int);
int findMatches(int[], int[], int);


int main() {
	//Declare variables
	int SIZE = 5;
	int lottery[5];
	int user[5];
	int matches;

	//Generate the lottery numbers
	generateNumbers(lottery, SIZE);

	//Get user input
	cout << "Pick 5 numbers between 0 and 9 " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Input a number: ";
		cin >> user[i];
	}
	//Find matches
	matches = findMatches(lottery, user, SIZE);

	//Output user array
	cout << "User's user: ";
	for (int j = 0; j < SIZE; j++)
		cout << user[j];
	cout << "\n";

	//Output lottery array
	cout << "Lottery Pick 5: ";
	for (int k = 0; k < SIZE; k++)
		cout << lottery[k];
	cout << "\n";
	
	//Output number of matches
	cout << "The total number of matches = " << matches << endl;
	if (matches == 5)
		cout << "You are a grand prize winner!";

	return 0;
}
void generateNumbers(int lottery[], int SIZE) {
	//Declare min and max constants
	const int MAX_VALUE = 9, MIN_VALUE = 0;

	//Generate random seed based off of time
	unsigned seed = time(0);
	srand(seed);

	//Generate the random array
	for (int i = 0; i < SIZE; i++) {
		lottery[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);
	}

}

int findMatches(int lottery[], int user[], int SIZE) {
	//Initialize matches
	int matchesFound = 0;

	//Check for any matches
	for (int i = 0; i < SIZE; i++) {
		if (lottery[i] == user[i]) {
			matchesFound++;
		}
	}
	return matchesFound;
}

/*OUTPUT:
Pick 5 numbers between 0 and 9
Input a number: 1
Input a number: 2
Input a number: 3
Input a number: 4
Input a number: 5
User's Guess: 12345
Lottery Pick 5: 48747
The total number of matches = 1
Press any key to continue . . .
*/