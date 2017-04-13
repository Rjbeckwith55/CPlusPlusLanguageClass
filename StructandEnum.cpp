/*
Robert Beckwith
StructandEnum.cpp
4/12/17
Structured and Enumerated Data
Descr:
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Purpose { BUSINESS = 1, PERSONAL };
struct Car {
	string carMake;
	string carModel;
	int yearModel;
	double cost;
	Purpose purp;
};

void displayCar(Car car) {
	cout << fixed;
	cout << setprecision(2);
	//Display the car
	cout << setw(15) << car.carMake;
	cout << setw(15) << car.carModel;
	cout << setw(15) << car.yearModel;
	cout << setw(15) << car.cost;
	switch (car.purp) {
	case BUSINESS:
		cout << setw(15) << "BUSINESS";
		break;
	case PERSONAL:
		cout << setw(15) << "PERSONAL";
		break;
	}
	cout << endl;

}



int main() {
	//Initialize car array with the first 3 elements
	Car car[10] = { { "Ford","Taurus",1997,21000.00, BUSINESS},
			 { "Honda","Accord",1992,11000.00, BUSINESS},
			 {"Lamborghini","Aventador",2011,390000.00, PERSONAL} };
	int purpNum;
	//Get input for the 4th element 
	cout << "Enter the car make: ";
	getline(cin, car[3].carMake);
	cout << "Enter the car model: ";
	getline(cin, car[3].carModel);
	cout << "Enter the car year: ";
	cin >> car[3].yearModel;
	cout << "Enter the car cost: ";
	cin >> car[3].cost;
	cout << "Enter the pupose of the car(1 for Business and 2 for Personal): ";
	cin >> purpNum;
	car[3].purp = static_cast<Purpose>(purpNum);

	//Display the make, model,year,cost, and purpose of the cars in the array
	cout << left << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Year" << setw(15) << "Cost" << setw(15) << "Purpose" << endl;
	for (int i = 0; i < 4; i++) {
		displayCar(car[i]);
	}


	return 0;
}
