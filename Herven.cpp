#include <iostream>
#include <string>
#include <fstream>

using namespace std;


float calGrade(float FG, int Exam1, int Exam2, int HW, int FEG , int ID) {
	FG = ((.20)*(Exam1)) + ((.20)*(Exam2)) + ((.35)*(HW)) + ((.25)*(FEG));
	return FG;
}

void writeFile(float FG, int Exam1, int Exam2, int HW, int FEG, int ID, char FLG) {
	ofstream outFile;
	outFile.open("Final.dat");
	cout << "OUTPUT";
	if ((FG <= 100) && (FG >= 90))
	{
		FLG = 'A';
	}
	if ((FG <= 90) && (FG >= 80))
	{
		FLG = 'B';
	}
	if ((FG <= 80) && (FG >= 70))
	{
		FLG = 'C';
	}
	if ((FG <= 70) && (FG >= 60))
	{
		FLG = 'D';
	}
	if ((FG <= 60) && (FG >= 0))
	{
		FLG = 'F';
	}
	outFile << ID << Exam1 << Exam2 << HW << FEG << FG << FLG;

}

void readFile(float FG, int Exam1, int Exam2, int HW, int FEG, int ID, char FLG) {
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
			FG = calGrade(FG, Exam1, Exam2, HW, FEG, ID);
			writeFile(FG, Exam1, Exam2, HW, FEG, ID, FLG);
		}

		
	}
	inFile.close();
}


int main() {
	int ID=0, Exam1=0, Exam2=0, HW=0, FEG=0;
	float FG=0.0;
	char FLG=' ';
	readFile(FG, Exam1, Exam2, HW, FEG, ID,FLG);
	system("pause");

}