#include <iostream>
#include <string>
#include <fstream>

using namespace std;


float calGrade(float FG[20], int Exam1, int Exam2, int HW, int FEG , int ID, int counter) {
	FG[counter] = ((.20)*(Exam1)) + ((.20)*(Exam2)) + ((.35)*(HW)) + ((.25)*(FEG));
	return FG[counter];
}

void writeFile(float FG[20], int Exam1, int Exam2, int HW, int FEG, int ID, char FLG, int counter) {

	ofstream outFile;
	outFile.open("Final.dat",ios_base::app);
	cout << "OUTPUT"<<endl;
	if ((FG[counter] <= 100) && (FG[counter] >= 90))
	{
		FLG = 'A';
	}
	if ((FG[counter] <= 90) && (FG[counter] >= 80))
	{
		FLG = 'B';
	}
	if ((FG[counter] <= 80) && (FG[counter] >= 70))
	{
		FLG = 'C';
	}
	if ((FG[counter] <= 70) && (FG[counter] >= 60))
	{
		FLG = 'D';
	}
	if ((FG[counter] <= 60) && (FG[counter] >= 0))
	{
		FLG = 'F';
	}

	counter++;

	outFile << "ID: " << ID << " Exam1: " << Exam1 << " Exam2: " << Exam2 << " HW: " << HW << " Final Exam Grade: " << FEG << " Final Grade: " << FG[counter] << " Final Letter Grade: " << FLG << endl;


}

int readFile(float FG[20], int Exam1, int Exam2, int HW, int FEG, int ID, char FLG) {
	int counter = 0;
	ifstream inFile;
	inFile.open("class.dat");

	if (inFile.fail())
	{
		cerr << "Error" << endl;
	}
	else
	{
		
		char g;
		while (!inFile.eof()) {
			inFile >> ID >> Exam1 >> Exam2 >> HW >> FEG;
			FG[counter] = calGrade(FG, Exam1, Exam2, HW, FEG, ID,counter);
			writeFile(FG, Exam1, Exam2, HW, FEG, ID, FLG,counter);
			counter++;
		}

		
	}
	inFile.close();
	return counter;

}

void sortArray(float FG[20]) {

}
float calAverage(float FG[20], int counter) {
	int total = 0;
	for (int i = 0; i < counter; i++) {
		total = total + FG[i];
	}
	
	return total/counter;
}
int calMed(float FG[20], int counter) {
	int temp = 0;
	if (counter % 2 != 0) {// is the # of elements odd?
		int temp = ((counter + 1) / 2) - 1;
		cout << "The median is " << FG[temp] << endl;
	}
	else {// then it's even! :)
		cout << "The median is " << FG[(counter / 2) - 1] << " and " << FG[counter / 2] << endl;
	}
	return FG[temp];
}
int calLowest(float FG[20], int counter) {
	int small;
	small = FG[0];
	
	for (int i = 1; i<counter; i++)
	{
		if (FG[i]<small)
			small = FG[i];
		
	}
	return small;
}

int calHighest(float FG[20], int counter) {
	int large;
	large = FG[0];
	for (int i = 1; i<counter; i++)
	{
		if (FG[i] > large)
			large = FG[i];
	}
	return large;
	
}
int main() {
	//A kludge that resets the file each time so it doesn't keep appending
	ofstream outFile;
	outFile.open("Final.dat");
	outFile.close();

	//Declarations
	int ID = 0, Exam1 = 0, Exam2 = 0, HW = 0, FEG = 0, counter = 0 , median = 0, lowest = 0, highest = 0;
	float FG[20];
	float average = 0;
	char FLG=' ';
	counter = readFile(FG, Exam1, Exam2, HW, FEG, ID, FLG);

	//Counter is being used as the size of the elements of the array that are used
	average = calAverage(FG, counter);
	median = calMed(FG, counter);
	lowest = calLowest(FG, counter);
	highest = calHighest(FG, counter);

	cout << average << endl;
	cout << median << endl;
	cout << lowest << endl;
	cout << highest << endl;

	system("pause");

}