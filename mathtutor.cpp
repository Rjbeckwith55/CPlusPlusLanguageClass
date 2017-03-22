/*Robert Beckwith
2/8/16
CIS 2541
Lab #3 - Making Decisions
Description: Program that displays 2 random integers that the user adds together
and the program checks if it is correct*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	//Constant declarations
	const int MAX_VALUE = 1500, MIN_VALUE = 500;
	//Variable declarations
	int num1, num2, sum, answer;

	//Generate a random integer 
	unsigned seed = time(0);
	srand(seed);
	num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);
	num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);

	//Output the math problem
	cout << setw(6) << right << num1 << endl;
	cout << "+" << setw(5) << right << num2 << endl;
	cout << "______" << endl;

	//Read the users answer
	cout << "Please enter your answer: ";
	cin >> answer;
	sum = num1 + num2;

	//Check the answer
	if (sum == answer)
		cout << "Congratulations! That is the correct answer!" << endl;
	else
		cout << "Your answer is incorrect the correct answer is: " << sum << endl;

	return 0;
}
/*   OUTPUT
   903
+ 1497
______
Please enter your answer: 12
Your answer is incorrect the correct answer is: 2400
Press any key to continue . . .

OUTPUT 2
  1122
+  744
______
Please enter your answer: 1866
Congratulations! That is the correct answer!
Press any key to continue . . .*/