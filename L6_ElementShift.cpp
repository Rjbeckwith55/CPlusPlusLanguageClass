/*Robert Beckwith
L6_ElementShift.cpp
3/22/16
CIS 2541
Lab #6
Descr: Shift the elements of the array over one
*/
// Chapter 9, Programming Challenge 12: Element Shifter
#include <iostream>
using namespace std;

// Function Prototypes
int *shift(int[], int);
void showArray(int[], int);

int main()
{
	const int SIZE = 5;
	int values[SIZE] = { 1, 2, 3, 4, 5 };

	// Display the contents of the array.
	cout << "The contents of the original array are:\n";
	showArray(values, SIZE);

	// Call the shift function to make a copy of
	// the array, with the elements shifted one
	// position toward the end if the array.
	int *arrCopy = shift(values, SIZE);

	// Display the contents of the new array.
	if (arrCopy) {
		cout << "The contents of the new array are:\n";
		showArray(arrCopy, SIZE + 1);
	}
	else
		cout << "Array not created" << endl;
	delete arrCopy;
	return 0;
}

// ********************************************************
// The shift function accepts an int array and an int     *
// indicating the array's size. The function returns a    *
// pointer to an array that is one element larger than    *
// the array that was passed as an argument. The elements *
// of the argument array are copied to the new array,     *
// shifted one position toward the end of the array.      *
// ********************************************************
int *shift(int arr[], int size)
{
	int *arrCopy = new int[size + 1];
	for (int i = size; i > 0; i--) {
		*(arrCopy + i) = *(arr + i - 1);
	}
	arrCopy[0] = 0;
	return arrCopy;  // only for compilation purposes; remove from final
}

// ********************************************************
// The showArray function displays the contents of an int *
// array.                                                 *
// ********************************************************
void showArray(int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << arr[index] << " ";
	}

	cout << endl << endl;
}
/*Output
The contents of the original array are:
1 2 3 4 5

The contents of the new array are:
0 1 2 3 4 5

Press any key to continue . . .*/
