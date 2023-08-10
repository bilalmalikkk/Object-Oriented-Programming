#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
    MyVector<int> vec(5);

    vec.insert(1);
    vec.insert(2);
    vec.insert(10);
    vec.insert(5);
    vec.insert(3);
    vec.insert(6);
    vec.insert(8);
    vec.insert(4);
    vec.insert(9);
    vec.insert(7);
    


    vec.display(); 

    vec.sortedInsert(11);
    vec.sortedInsert(12);

    vec.display();

    vec.insertionSort();

    vec.display(); 

    vec.remove();
    vec.remove();

    vec.display(); 

    
    return 0;
}
