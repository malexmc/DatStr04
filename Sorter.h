#ifndef Sorter_H
#define Sorter_H

#include <vector>

using namespace std;

class Sorter{
public:
    static vector<int>* mergeSort(vector<int>*);
    static vector<int>* insertionSort(vector<int>*);
    static vector<int>* bubbleSort(vector<int>*);
    static vector<int>* quickSort(vector<int>*);
    static bool isUnique1(vector<int>*, int first, int last);
    static bool isUnique2(vector<int>*, int first, int last);
    static bool isUnique3(vector<int>*, int first, int last);
    
private:
    static bool isSorted(vector<int>*);
    static vector<int>* merge(vector<int>*, vector<int>*);  
    Sorter(){};
};

#endif //Sorter_H
