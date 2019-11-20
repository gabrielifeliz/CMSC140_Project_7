/*
* Class: CMSC140 CRN 20780
* Instructor: Madvhi Shah
* Project7
* Description: A program that processes a string data file,
sorts data in ascending order, and saves this sorted data
into a data file named "sortedNamed.txt"
* Due Date:
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Gabriel I Feliz
*/



#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void readNames(ifstream &, string[], int);
void selectionSort(string[], int);
void showArray(string[], int);
void writeNames(ofstream &, string[], int);

// Main function
int main()
{
	// Declare and initialize original size of the array
	const int SIZE = 20;
	// Declare the variable for the number of names to read 
	int desiredSize;
	// Declare string literal to store the file name where the unsorted names are
	// Declare string array to store those unsorted names
	// Declare string literal to store the file name where the sorted names will be
	string file_Name, namesArray[SIZE], new_File_Name;
	// Declare ifstream object to read unsorted names from file "names.txt"
	ifstream  namesFile;
	// Declare ofstream object to write sorted names to a separate new file
	ofstream sortedNamesFile;

	// Prompt and enter file name
	cout << "Please enter the name of the file to read names from:" << endl;
	cin >> file_Name;

	// Open file with unsorted names
	namesFile.open(file_Name);

	// Call readNames function that is responsible for storing names into the string array 
	readNames(namesFile, namesArray, SIZE);

	// Prompt and enter numbers of names to read
	cout << "Enter number of names to read:" << endl;
	cin >> desiredSize;

	/* Everything from asking the user to enter the number of names to read 
	to saving the sorted names to a text file named “sortedNumbers” will process
	if the number of names to read is less than or equal to 
	the maximum size of the array (20).
	*/
	if (desiredSize <= SIZE)
	{
		cout << endl << "Here are the unsorted names:" << endl;
		cout << "--------------------------" << endl;
		// Call showArray function to display the unsorted names
		showArray(namesArray, desiredSize);
		cout << endl;

		// Call the selectionSort function to sort the names.
		selectionSort(namesArray, desiredSize);

		cout << endl << "Here are the sorted names:" << endl;
		cout << "-----------------------------" << endl;
		// Call showArray function again to display the sorted names
		showArray(namesArray, desiredSize);
		cout << endl;

		// Close file with unsorted names
		namesFile.close();

		// Prompt and enter file name where the sorted names will be written
		cout << endl << "Please enter the name of the file to save sorted names to:" << endl;
		cin >> new_File_Name;

		// Open or create file where the sorted name will be placed
		sortedNamesFile.open(new_File_Name);

		/* Call writeNames function that is responsible for 
		storing the sorted names into the new file */
		writeNames(sortedNamesFile, namesArray, desiredSize);

		// Close file with sorted names
		sortedNamesFile.close();
	}
	else // An error message is displayed for the number of names to read is greater than 20
	{
		cout << "Number of names to read cannot be greater than 20" << endl;
	}

	return 0;
}

// Function responsible for storing the unsorted names into the string array
void readNames(ifstream &namesFile, string namesArray[], int desiredSize)
{
	//The names will be read and stored into the string array if the file successfully opens
	if (namesFile) 
	{
		/*The for loops allows the program to start storing the first line
		in the file into the first element of the string array, the second line to
		the second element, and so on. It stops at whatever number the user entered
		for the number of names to read */
		for (int count = 0; count < desiredSize; count++)
		{
			getline(namesFile, namesArray[count]);
		}
	}	
	//An error message will be displayed if the file is not found
	else if (!namesFile)
	{
		cout << "Error: File not found" << endl;
		// exit() function is used to terminate the program after the error message is displayed
		exit(EXIT_FAILURE);
	}
	//An error message will be displayed if the file fails to open
	else if (namesFile.fail())
	{
		cout << "Error opening the file" << endl;
		// exit() function is used to terminate the program after the error message is displayed
		exit(EXIT_FAILURE);
	}
}

// Function responsible for sorting names
/* Arguments accepted are namesArray and desiredSize.
These arguments are of data types string and int, 
and they are passed from main function*/
void selectionSort(string namesArray[], int desiredSize)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (desiredSize - 1); startScan++)
	{
		minIndex = startScan;
		minValue = namesArray[startScan];
		for (int index = startScan + 1; index < desiredSize; index++)
		{
			if (namesArray[index] < minValue)
			{
				minValue = namesArray[index];
				minIndex = index;
			}
		}
		namesArray[minIndex] = namesArray[startScan];
		namesArray[startScan] = minValue;
	}
}

// Function responsible for showing the unsorted/sorted names 
/* Arguments accepted are namesArray and desiredSize.
These arguments are of data types string and int,
and they are passed from main function*/
void showArray(string namesArray[], int desiredSize)
{
	/*The for loops allows the program to show the names stored 
	in the elements of the string array. It stops at whatever 
	number the user entered for the number of names to read */
	for (int count = 0; count < desiredSize; count++)
	{
		cout << namesArray[count] << endl;
	}
}

// Function responsible for writing the sorted names to a file called "sortedNames.txt"
/* Arguments accepted are sortedNamesFile namesArray and desiredSize.
These arguments are of data types ofstream, string and int,
and they are passed from main function */
void writeNames(ofstream &sortedNamesFile, string namesArray[], int desiredSize)
{
	/*The for loops allows the program to write the names stored
	in the elements of the string array to each line in the file. 
	It stops at whatever number the user entered for the number of names to read */
	for (int count = 0; count < desiredSize; count++)
	{
		sortedNamesFile << namesArray[count] << endl;
	}
}