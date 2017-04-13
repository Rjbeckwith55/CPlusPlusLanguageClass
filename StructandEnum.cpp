/*
Robert Beckwith
StructandEnum.cpp
4/12/17
Structured and Enumerated Data
Descr: 
*/

#include <iostream>
#include <string>
using namespace std;

struct Car {
	string carMake;
	string carModel;
	int yearModel;
	double cost;
};

void displayCar(Car car[]) {
	cout << "Make" << "Model" << "Year" << "Cost" << "Purpose" << endl;
	for (int i = 0; i < 4; i++) {
		cout << car[i].carMake<< " ";
		cout << car[i].carModel << " ";
		cout << car[i].yearModel << " ";
		cout << car[i].cost << " ";
		cout << endl;
	}
}



int main() {
	Car car[10];
	car[0] = { "Ford","Taurus",1997,21000.00 };
	car[1] = { "Honda","Accord",1992,11000.00 };
	car[2] = { "Lamborghini","Aventador",2011,3900000.00 };
	cout << "Enter the car make: ";
	getline(cin, car[3].carMake);
	cout << "Enter the car model: ";
	getline(cin, car[3].carModel);
	cout << "Enter the car year: ";
	cin >> car[3].yearModel;
	cout << "Enter the car cost";
	cin >> car[3].cost;
	displayCar(car);

	return 0;
}