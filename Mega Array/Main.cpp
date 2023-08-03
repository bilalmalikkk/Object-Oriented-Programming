#include <iostream>
#include "MegaArray.h"
using namespace std;

int main() 
{
    MegaArray<int> arr(10);

    for (int i = 0; i < arr.size(); i++)
    {
        arr.add(rand() % 100);
        
    }


    cout << "Original array: ";
    arr.display();

    MergeSort(arr, 0, arr.size() - 1);
    cout << "Merge Sorted array: ";
    arr.display();

    InsertionSort(arr);
    cout << "Insertion Sorted array: ";
    arr.display();

    return 0;
}
