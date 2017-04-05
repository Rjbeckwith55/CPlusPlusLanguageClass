// Chapter 10, Programming Challenge 3: Word Counter
/*
	Robert Beckwith
	L7_WordCounter.cpp
	4/5/2017
	CIS 2541
	Lab #7 Chars, C-strings, string Class
	Decription: Program reads a set of characters and determines how many words are included.

*/
#include <iostream>
#include <string>
using namespace std;

// Function Prototype
int wordCount (char *userEntry);

int main()
{
    // Constants
    const int MAX_LENGTH = 150;

    // Local variables
    char userWords[MAX_LENGTH+1] ;
    int wCount = 0;

    // Get the user input line of text.
    cout << "Enter text less than or equal to " << MAX_LENGTH << " characters:\n";
    cin.getline(userWords,  MAX_LENGTH+1);

    // Count the number of words entered.
    wCount = wordCount (userWords);

    // Display the number of words entered
    cout << "\nNumber of words in the entered text is: " << wCount << endl;
    return 0;
}

// ********************************************************
// **
// **   Function Name:  wordCount 
// **   This function counts the # of space-delimited words 
// **   in a text string, and returns the count to the caller.
// **
// **
// ********************************************************
int wordCount (char *userEntry)
{ 
	int count = 0;
	string word = userEntry;

	//Loop through the string checking each character
	for (int i = 0; i < word.length(); i++)
	{
		//Check if there are alphabetic characters and not blank spaces
		if (word[i] != NULL && isalpha(word[i]))
		{
			//Check if the next line is a blank space if it is that is the end of a word
			if (word[i + 1] == NULL || !isalpha(word[i + 1]))
				count++;
		}
	}

    return count;
}

/* 
			SAMPLE OUTPUT
Enter text less than or equal to 150 characters:
1    22      3333     44444

Number of words in the entered text is: 0
Press any key to continue . . .


Enter text less than or equal to 150 characters:
testing

Number of words in the entered text is: 1
Press any key to continue . . .


Enter text less than or equal to 150 characters:
testing      a     11      222    three   4  five

Number of words in the entered text is: 4
Press any key to continue . . .
*/

