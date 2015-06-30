#include <iostream>
#include <vector>
#include <cmath>
#include "Sorter.h"

using namespace std;

//Bubble sorts an int vector in ascending order. Creates a pointer which will need
//to be taken care of later.

vector<int>* Sorter::bubbleSort(vector<int>* unsorted) {

  // Make a new array
	vector<int>* sorter = new vector<int>;

  //copy parameter array into new array
  for (unsigned int ii = 0; ii < unsorted->size(); ii++){
    sorter->push_back(unsorted->at(ii));
  }

  //once filled, begin sorting the new array.
  for (unsigned int ii = 0; ii < sorter->size(); ii++) {
      bool swapped = false;
      for (unsigned int jj = 0; jj < sorter->size() - ii; jj++) {
          if ((jj + 1 < sorter->size())) {
              if (sorter->at(jj) > sorter->at(jj + 1)) {
                  int temp = sorter->at(jj + 1);
                  sorter->at(jj + 1) = sorter->at(jj);
                  sorter->at(jj) = temp;
                  swapped = true;
              }
          }
      }
      if (!swapped) {
          return sorter;
      }
  }

  //return the new, sorted array
  return sorter;
}



//tests to see if an int vector is sorted in ascending order
bool Sorter::isSorted(vector<int>* sort_vector){
  for(unsigned int i = 0; i < sort_vector->size()-1; i++){
    if((*sort_vector)[i] > (*sort_vector)[i+1]){
      return false;
    }
  }
  return true;
}

//merges two int vectors together in ascending sorted order
vector<int>* Sorter::merge(vector<int>* a, vector<int>* b){
  unsigned int ia = 0;
  unsigned int ib = 0;
  vector<int>* sorter = new vector<int>;
  while(ia < a->size() || ib < b->size()){
    if(ib == b->size()){
      sorter->push_back((*a)[ia]);
      ia++;
    }
    else if(ia == a->size()){
      sorter->push_back((*b)[ib]);
      ib++;
    }
    else if((*a)[ia] < (*b)[ib]){
      sorter->push_back((*a)[ia]);
      ia++;
    }
    else{
      sorter->push_back((*b)[ib]);
      ib++;
    }
  }
  return sorter;
}


//merge sorts an vector of strings in ascending order. Does not alter the
//parmeter vector
vector<int>* Sorter::mergeSort(vector<int>* unsorted){

  /*cout << "taking in:";
  for (unsigned int ii = 0; ii < merger->size(); ii++){
    cout << merger->at(ii) << " ";
  }
  cout << endl;*/
  
  
  if(unsorted->size() <= 1){
    return unsorted;
  }
  if(!Sorter::isSorted(unsorted)){

    // Make a new array
	  vector<int>* sorter = new vector<int>;

    //copy parameter array into new array
    for (unsigned int ii = 0; ii < unsorted->size(); ii++){
      sorter->push_back(unsorted->at(ii));
    }

    vector<int>* temp1 = new vector<int>;
    vector<int>* temp2 = new vector<int>;
    unsigned int middle = sorter->size()/2;

    //distribute the elements of the array to sort into temp1 if they appear
    //before the middle of the array, and temp2 if after.
    for(unsigned int i = 0; i < sorter->size(); i++){
      if(i < middle){
        temp1->push_back((*sorter)[i]);
      }
      else{
        temp2->push_back((*sorter)[i]);
      }
    }
    temp1 = mergeSort(temp1);
    temp2 = mergeSort(temp2);
    sorter = merge(temp1, temp2);
    delete temp1;
    delete temp2;
      /*cout << "giving back:";
      for (unsigned int ii = 0; ii < merger->size(); ii++){
        cout << merger->at(ii) << " ";
      }
      cout << endl;*/
    return sorter;
  }
  
  /*cout << "did nothing:";
  for (unsigned int ii = 0; ii < merger->size(); ii++){
    cout << merger->at(ii) << " ";
  }
  cout << endl;*/
  return unsorted;
}


//insertion sorts an int vector in ascending order
vector<int>* Sorter::insertionSort(vector<int>* unsorted){
  vector<int>* sorted = new vector<int>;
  sorted->resize(unsorted->size());
  int unsorted_index = 0;
  for(unsigned int nextPos = unsorted_index; nextPos < unsorted->size(); nextPos++){
    int nextVal = (*unsorted)[unsorted_index];
    int tempPos = nextPos;
    while(tempPos > 0 && (*sorted)[tempPos-1] > nextVal){
      (*sorted)[tempPos] = (*sorted)[tempPos-1];
      tempPos--;
    }
    (*sorted)[tempPos] = nextVal;
    unsorted_index++;
  }
  return sorted;
}



//quickSorts a vector of ints. Does not alter the parameter array.

vector<int>* Sorter::quickSort(vector<int>* unsorted){

  cout << "array to sort: ";
  for (unsigned int ii = 0; ii < unsorted->size(); ii++){
    cout << unsorted->at(ii) << ",";
  }
  cout << endl;

  // Make a new array
  vector<int>* sorter = new vector<int>();

  //copy parameter array into new array
  for (unsigned int ii = 0; ii < unsorted->size(); ii++){
    sorter->push_back(unsorted->at(ii));
  }

  if (sorter->size() > 1){
    unsigned int middle = (sorter->size()/2);
    int pivot = sorter->at(middle);
    unsigned int first = 0;
    unsigned int last = sorter->size() - 1;
    cout << "a" << endl;
    while (first <= last){
      while(sorter->at(first) < pivot){
        first++;
        //cout << "first: " << first << endl;
      }
      while(sorter->at(last) > pivot){
        last--;
      }
      cout << "first:" << first << endl << "last: " << last << endl;
      if(first <= last){
        int temp = sorter->at(last);
        sorter->at(last) = sorter->at(first);
        sorter->at(first) = temp;
        first++;
        last--;
      }
    }

    //store the left half of the sorter vector in left
    cout << "b" << endl;
    vector<int>* left = new vector<int>();
    for (unsigned int ii = 0; ii <= last; ii++){
      left->push_back(sorter->at(ii));
    }

    //store the right half of the sorter vector in right
    cout << "c" << endl;
    vector<int>* right = new vector<int>();
    for (unsigned int ii = first; ii < sorter->size(); ii++){
      right->push_back(sorter->at(ii));
    }

    //quick sort the halves and destroy the left and right vectors
    cout << "d" << endl;
    vector<int>* sorted_left = Sorter::quickSort(left);
    vector<int>* sorted_right = Sorter::quickSort(right);

    //push the halves into the final array.
    cout << "e" << endl;
    vector<int>* sorted = new vector<int>(); 
    
    if(sorted_left->size() > 0){
      for(unsigned int ii = 0; ii < sorted_left->size(); ii++){
        sorted->push_back(sorted_left->at(ii));
      }
    }

    if(sorted_right->size() > 0){
      for(unsigned int ii = 0; ii < sorted_right->size(); ii++){
        sorted->push_back(sorted_right->at(ii));
      }
    }
    cout << "f" << endl;

    // clean-up
    cout << "l del" << endl;
    cout << left << endl;
    cout << sorted_left << endl;
    delete left;
    cout << "r del" << endl;
    delete right;
    cout << "rsort del" << endl;
    delete sorted_right;
    cout << "lsort del" << endl;
    delete sorted_left;



    cout << "g" << endl;
    return sorted;      
  }

  return unsorted;
}






