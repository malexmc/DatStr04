//In the file containing the main function you must write at the top in a comment section the following information
//Author: Will Hauber, John Mikolay, Matthew McClellan
//Course title: Data Structures
////Course number: CS2028
////Instructor: Anca Ralescu
//TA: Suryadip Chakraborty
//Abstract: Used to compare the sorting efficiency of various sorting alrorithms.
//Preconditions: User will need to follow terminal prompts from the application during runtime.
//Postconditions: Information printed to screen
//Credit: Thanks to Dr. Paul Talaga for his Makefile, and to Rosettacode.org for the 
// quicksorting algorithm pseudocode


//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Sorter.h"


using namespace std;

// <will>
// forward declarations
int getPositiveInteger();
int getInteger();
bool getYesOrNo();

vector<int>* getRandomlyGeneratedVector(unsigned int length);
vector<int>* getListFromUser(unsigned int length);
void printList(vector<int>* list);

int main()
{
	// <will>
	// Seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));

	// <will>
	// Display program information
	cout << "Algorithm Analysis Program" << endl << endl;
	cout << "  This program sorts lists using multiple sorting algorithms. " << endl;
	cout << "  Merge and Quick sort are used for large lists, and Bubble " << endl;
	cout << "  and insertion sort are used for small lists." << endl << endl;

	// <will>
	// we will break out of the loop later if necessary
	while (true)
	{
		// <will>
		// Get the threshold value
		unsigned int threshold = 0;
		cout << "Enter threshold value. This value is the lenth below which an" << endl;
		cout << "array is considered small." << endl;
		threshold = getPositiveInteger();
		cout << endl;

		// <will>
		// Get the size
		unsigned int size = 0;
		cout << "Enter size. Only arrays of size less than or equal to 100 may" << endl;
		cout << "manually entered in or printed." << endl;
		size = getPositiveInteger();
		cout << endl;

		// <will>
		// Declare the unsorted list and displayList boolean
		vector<int>* unsorted = 0;
		bool displayList = false;

		// <will>
		// If the size is reasonably low, allow for manual input/printing
		if (size <= 100)
		{
			// <will>
			// Determine if we should get the list manually
			cout << "Enter list manually? (y/n)" << endl;
			bool enterManually = getYesOrNo();
			cout << endl;

			if (enterManually)
			{
				// <will>
				// If we should get the list manually, call the appopriate helper method
				cout << "Enter elements one at a time." << endl;
				unsorted = getListFromUser(size);
				cout << endl;
			}
			else
			{
				// <will>
				// Otherwise, generate the list randomly
				unsorted = getRandomlyGeneratedVector(size);
			}
			
			// <will>
			// Determine if we should print the list
			cout << "Should list be displayed? (y/n)" << endl;
			displayList = getYesOrNo();
			cout << endl;
		}

		// <will>
		// If the size is not reasonably low, randomly generate the list and don't print
		else
		{
			unsorted = getRandomlyGeneratedVector(size);
		}

		// <will>
		// Print the unsorted list
		if (displayList)
		{
			cout << "List before sorting:" << endl;
			printList(unsorted);
			cout << endl;
		}

		// <will>
		// Sort the list using each combination.
		// Make sure that hybrid sort is not modifying unsorted!
		vector<int>* sortedMB = Sorter::hybridSort(unsorted, "mergeSort", "bubbleSort", threshold);
		int mbCount = Sorter::comparisonCounter;
                Sorter::comparisonCounter = 0;
                vector<int>* sortedMI = Sorter::hybridSort(unsorted, "mergeSort", "insertionSort", threshold);
		int miCount = Sorter::comparisonCounter;
                Sorter::comparisonCounter = 0;
                vector<int>* sortedQB = Sorter::hybridSort(unsorted, "quickSort", "bubbleSort", threshold);
		int qbCount = Sorter::comparisonCounter;
                Sorter::comparisonCounter = 0;
                vector<int>* sortedQI = Sorter::hybridSort(unsorted, "quickSort", "insertionSort", threshold);
                int qiCount = Sorter::comparisonCounter;
                Sorter::comparisonCounter = 0;
                
		// <will>
		// Print the sorted list
		if (displayList)
		{
			cout << "List after sorting:" << endl;
			printList(sortedQB);
			cout << endl;
		}
                
                // <john>
                // Ask if comparison count should be shown.
                cout << "Display comparison count for each algorithm? (y/n)" << endl;
			bool displayComparisonCount = getYesOrNo();
			cout << endl;
                
                        if( displayComparisonCount ){
                            cout << "Total Comparisons" << endl;
                            cout << "Merge and Bubble: " << mbCount << endl;
                            cout << "Merge and Insertion: " << miCount << endl;
                            cout << "Quick and Bubble: " << qbCount << endl;
                            cout << "Quick and Insertion: " << qiCount << endl;
                        }
                        
		// <will>
		// Clean up
		delete unsorted;
		unsorted = 0;
		delete sortedMB;
		sortedMB = 0;
		delete sortedMI;
		sortedMI = 0;
		delete sortedQB;
		sortedQB = 0;
		delete sortedQI;
		sortedQI = 0;

		// <will>
		// Ask if we should sort another list
		cout << "Sort another list? (y/n)" << endl;
		bool sortAgain = getYesOrNo();
		cout << endl;

		if (!sortAgain)
		{
			break;
		}
	}

	return 0;
}

int getPositiveInteger()
{
	int response = 0;
	cout << " :";
	cin >> response;

	// <will>
	// Make sure the inputed number is > 0
	while (response < 1)
	{
		cout << "Please enter a positive integer." << endl << " :";
		cin >> response;
	}

	return response;
}

int getInteger()
{
	int response = 0;
	cout << " :";
	cin >> response;
	while (cin.fail())
	{
		cout << "Please enter an integer." << endl << " :";
		cin >> response;
	}
	return response;
}

bool getYesOrNo()
{
	string response = "";
	cout << " :";
	cin >> response;

	// <will>
	// Make sure the inputed text is either y, Y, n, or N
	while (response != "y" && response != "Y" && response != "n" && response != "N")
	{
		cout << "Please enter y/n." << endl << " :";
		cin >> response;
	}

	return response == "y" || response == "Y";
}

vector<int>* getRandomlyGeneratedVector(unsigned int length)
{
	vector<int>* newVector = new vector<int>();
	for (unsigned int ii = 0; ii < length; ii++)
	{
		// <will>
		// Generate numbers that are in the range [-2 * length, 2 * length)
		newVector->push_back((rand() % (length * 4)) - length * 2);
	}
	return newVector;
}

vector<int>* getListFromUser(unsigned int length)
{
	vector<int>* newVector = new vector<int>();
	for (unsigned int ii = 0; ii < length; ii++)
	{
		// <will>
		// Ask the user for a number each iteration
		newVector->push_back(getInteger());
	}
	return newVector;
}

void printList(vector<int>* list)
{
	for (unsigned int ii = 0; ii < list->size(); ii++)
	{
		cout << (*list)[ii] << " ";
	}
	cout << endl;
}
