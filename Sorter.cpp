//#include "stdafx.h"

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
  
  //printing
  /*
  cout << "copied." << endl;
  for (unsigned int ii = 0; ii < unsorted->size(); ii++){
    cout << sorter->at(ii) << ",";
  }
  cout << endl;*/
  
  
  //once filled, begin sorting the new array.
	for (unsigned int ii = 0; ii < sorter->size(); ii++) {
		bool swapped = false;
		for (unsigned int jj = 0; jj < sorter->size() - ii; jj++) {
			if (jj + 1 < sorter->size()) {
				if (sorter->at(jj) > sorter->at(jj + 1)) {
					int temp = sorter->at(jj + 1);
					sorter->at(jj + 1) = sorter->at(jj);
					sorter->at(jj) = temp;
					swapped = true;
				}
			}
		}
      
		if (!swapped) {
			//cout << "returning" << endl;
			return sorter;
		}
	}

	//return the new, sorted array
	for (unsigned int ii = 0; ii < unsorted->size(); ii++) {
		//cout << sorter->at(ii) << ",";
	}
	return sorter;
}



//tests to see if an int vector is sorted in ascending order
bool Sorter::isSorted(vector<int>* sort_vector){
	for(unsigned int i = 0; i < sort_vector->size()-1; i++) {
		if((*sort_vector)[i] > (*sort_vector)[i+1]) {
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
    temp1 = Sorter::mergeSort(temp1);
    temp2 = Sorter::mergeSort(temp2);
    sorter = Sorter::merge(temp1, temp2);
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

/*
  cout << "array to sort: ";
  for (unsigned int ii = 0; ii < unsorted->size(); ii++){
    cout << unsorted->at(ii) << ",";
  }
  cout << endl;
*/


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
    while (first <= last){
      while(sorter->at(first) < pivot){
        first++;
      }
      while(sorter->at(last) > pivot){
        last--;
      }
      if(first <= last){
        int temp = sorter->at(last);
        sorter->at(last) = sorter->at(first);
        sorter->at(first) = temp;
        first++;
        last--;
      }
    }

    //store the left half of the sorter vector in left
    vector<int>* left = new vector<int>();
    for (unsigned int ii = 0; ii <= last; ii++){
      left->push_back(sorter->at(ii));
    }

    //store the right half of the sorter vector in right
    vector<int>* right = new vector<int>();
    for (unsigned int ii = first; ii < sorter->size(); ii++){
      right->push_back(sorter->at(ii));
    }

    //quick sort the halves and destroy the left and right vectors
    vector<int>* sorted_left = Sorter::quickSort(left);
    vector<int>* sorted_right = Sorter::quickSort(right);

    //push the halves into the final array.
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

    // clean-up
    delete left;
    delete right;
    delete sorted_right;
    delete sorted_left;

    return sorted;      
  }


  return sorter;
}




// Uses a combination of mergesort and bubble sort to sort integers 
// in ascending order. Does not alter the parameter vector.

vector<int>* Sorter::hybridSort(vector<int>*    unsorted, 
                        string          large,
                        string          small,
                        unsigned int    t
                       ){
  
  
  
  
      // Make a new array
    vector<int>* sorter = new vector<int>();

    // check to make sure that large and small sort method strings
    // contain valid methods.
    if (!(small.compare("bubbleSort") ==0 || small.compare("insertionSort") == 0)){
        cout << "Please enter a valid small sort method (\"bubbleSort\""  
             << "or \"insertionSort\")\n\n";
         return sorter;
    }
    
    if (!(large.compare("mergeSort") == 0 || large.compare("quickSort") == 0)){
        cout << "Please enter a valid large sort method (\"mergeSort\""  
             << "or \"quickSort\")\n\n";
         return sorter;
    }
    
    
    //copy parameter array into new array
    for (unsigned int ii = 0; ii < unsorted->size(); ii++){
      sorter->push_back(unsorted->at(ii));
    }
    
  // if too small to sort, return
  if(sorter->size() <= 1){
    return sorter;
  }
  
  //if under the threshold, but sortable, use small sort
  if(sorter->size() <= t){
    if(small.compare("bubbleSort") == 0){
        return Sorter::bubbleSort(unsorted);
    }
    if(small.compare("insertionSort") == 0){
        return Sorter::insertionSort(unsorted);
    }  
  
  }
  
  // if above threshold, large sort
  if(!Sorter::isSorted(sorter)){

    
    //Perform mergesort if chosen
    if(large.compare("mergeSort") == 0){
        //cout << "merge" << endl;

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
        temp1 = Sorter::hybridSort(temp1, large, small, t);
        temp2 = Sorter::hybridSort(temp2, large, small, t);
        sorter = Sorter::merge(temp1, temp2);
        delete temp1;
        delete temp2;
          /*cout << "giving back:";
          for (unsigned int ii = 0; ii < merger->size(); ii++){
            cout << merger->at(ii) << " ";
          }
          cout << endl;*/
        return sorter;
    }
    
    //perform quicksort of chosen
    if(large.compare("quickSort") == 0){

      if (sorter->size() > 1){
        unsigned int middle = (sorter->size()/2);
        int pivot = sorter->at(middle);
        unsigned int first = 0;
        unsigned int last = sorter->size() - 1;
        while (first <= last){
          while(sorter->at(first) < pivot){
            first++;
          }
          while(sorter->at(last) > pivot){
            last--;
          }
          if(first <= last){
            int temp = sorter->at(last);
            sorter->at(last) = sorter->at(first);
            sorter->at(first) = temp;
            first++;
            last--;
          }
        }
            
        //store the left half of the sorter vector in left
        vector<int>* left = new vector<int>();
        for (unsigned int ii = 0; ii <= last; ii++){
          left->push_back(sorter->at(ii));
        }

        //store the right half of the sorter vector in right
        vector<int>* right = new vector<int>();
        for (unsigned int ii = first; ii < sorter->size(); ii++){
          right->push_back(sorter->at(ii));
        }

        //quick sort the halves and destroy the left and right vectors
        vector<int>* sorted_left = Sorter::hybridSort(left, large, small, t);
        vector<int>* sorted_right = Sorter::hybridSort(right, large, small, t);

        //push the halves into the final array.
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
    

        // clean-up
        delete left;
        delete right;
        delete sorted_right;
        delete sorted_left;

        return sorted;      
      }

    return sorter;
    
    }
  }
  
  /*cout << "did nothing:";
  for (unsigned int ii = 0; ii < merger->size(); ii++){
    cout << merger->at(ii) << " ";
  }
  cout << endl;*/
  return sorter;  
}







