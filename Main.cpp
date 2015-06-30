

// Thanks to Dr. Paul Talaga for his Makefile, and to Rosettacode.org for the 
// quicksorting algorithm pseudocode

#include <iostream>
#include <vector>
#include "Sorter.h"
using namespace std;

int main(){
  vector<int> poop;
  poop.push_back(4);
  poop.push_back(3);
  poop.push_back(5);
  poop.push_back(2);
  poop.push_back(6);
  poop.push_back(7);
  poop.push_back(8);
  poop.push_back(1);
  poop.push_back(9);
  poop.push_back(0);

  vector<int>* sorted = new vector<int>;
  sorted = Sorter::hybridSort(&poop, "QuickSort", "insertionSort", 2);

/*
  cout << "Sorted: ";
  for (unsigned int ii = 0; ii < sorted->size(); ii++){
    cout << sorted->at(ii) << ',';
  }
  cout << endl;

  cout << "poop: ";
  for (unsigned int ii = 0; ii < sorted->size(); ii++){
    cout << poop.at(ii) << ',';
  }
  cout << endl;
*/

  return 0;
}
