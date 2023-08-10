#pragma once
#include <iostream>;
using namespace std;

template <typename T>
class MyVector
{
private:
    T* arr;
    int capacity;
    int currSize;
    void reSize() 
    {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < currSize; i++) 
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    MyVector() 
    {
        capacity = 10;
        currSize = 0;
        arr = new T[capacity];
    }

    MyVector(int size) 
    {
        capacity = size;
        currSize = 0;
        arr = new T[capacity];
    }

    MyVector(const MyVector& orig) 
    {
        capacity = orig.capacity;
        currSize = orig.currSize;
        arr = new T[capacity];
        for (int i = 0; i < currSize; i++) 
        {
            arr[i] = orig.arr[i];
        }
    }

    MyVector& operator= (const MyVector& rhs) 
    {
        if (this != &rhs) 
        {
            delete[] arr;
            capacity = rhs.capacity;
            currSize = rhs.currSize;
            arr = new T[capacity];
            for (int i = 0; i < currSize; i++) 
            {
                arr[i] = rhs.arr[i];
            }
        }
        return *this;
    }

    ~MyVector() 
    {
        delete[] arr;
    }

    int getSize() const 
    {
        return currSize;
    }

    int getCapacity() const 
    {
        return capacity;
    }

    void insert(const T& val) 
    {
        if (currSize == capacity) 
        {
            reSize();
        }
        arr[currSize++] = val;
    }

    T remove() {
        if (currSize == 0) 
        {
            throw out_of_range("Vector is empty");
        }
        return arr[--currSize];
    }

    T& operator[](int index) 
    {
        if (index < 0 || index >= currSize) 
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    bool sortedInsert(int val) 
    {
        if (currSize == capacity) 
        {
            reSize();
        }
        int i = currSize - 1;
        while (i >= 0 && arr[i] > val) 
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
        currSize++;
        return true;
    }

    void insertionSort() 
    {
        for (int i = 1; i < currSize; i++) 
        {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }



    void display() const 
    {
        for (int i = 0; i < currSize; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << std::endl;
    }

    
};

