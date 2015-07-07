// AlgorithmAnalysis.cpp : Defines the entry point for the console application.
//
/*------------------------------------------------------
 -------------------------------------------------------
 This file is modified to easily test th comparison counts
 or each sort. It should be used for testing ONLY.
 It iterates over a range of thresholds which can modified at 
 line 58. The list size can be modified at line 60.
 Print statements can be adjusted at lines 81-84 
 It will loop until all threshold values have ran then ask if 
 you would like it run again. All sorts and threshold values
 run on the same list to maintain consistency in comparing results.
 
 */
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

                for(int i = 8; i<17; i++){
                    threshold = i;
		unsigned int size = 50;

		vector<int>* unsorted = 0;
		
			unsorted = getRandomlyGeneratedVector(size);

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
                            //cout << mbCount << endl;
                            //cout << miCount << endl;
                            //cout << qbCount << endl;
                            cout << qiCount << endl;

                        
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
	}
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
