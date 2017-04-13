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

struct Car {
	string carMake;
	string carModel;
	int yearModel;
	double cost;
	enum Purpose { BUSINESS = 1, PERSONAL };
};

void displayCar(Car car[]) {
	cout << fixed;
	cout << setprecision(2);
	cout << left << setw(10) << "Make" << setw(10) << "Model" << setw(10) << "Year" << setw(10) << "Cost" << setw(10) << "Purpose" << endl;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << car[i].carMake;
		cout << setw(10) << car[i].carModel;
		cout << setw(10) << car[i].yearModel;
		cout << setw(10) << car[i].cost;
		cout << endl;
	}
}



int main() {
	Car car[10];
	car[0] = { "Ford","Taurus",1997,21000.00, 1 };
	car[1] = { "Honda","Accord",1992,11000.00, 1 };
	car[2] = { "Lamborghini","Aventador",2011,390000.00, 1 };
	cout << "Enter the car make: ";
	getline(cin, car[3].carMake);
	cout << "Enter the car model: ";
	getline(cin, car[3].carModel);
	cout << "Enter the car year: ";
	cin >> car[3].yearModel;
	cout << "Enter the car cost: ";
	cin >> car[3].cost;
	displayCar(car);

	return 0;
}