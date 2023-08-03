#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MegaArray {
private:
    int capacity;
    int currSize;
    T* data;

    void reSize() 
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < currSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    MegaArray(int size) 
    {
        capacity = size;
        currSize = 0;
        data = new T[capacity];
    }

    MegaArray(const MegaArray& other) 
    {
        capacity = other.capacity;
        currSize = other.currSize;
        data = new T[capacity];
        for (int i = 0; i < currSize; i++) 
        {
            data[i] = other.data[i];
        }
    }

    MegaArray& operator=(const MegaArray& other) 
    {
        if (this != &other) 
        {
            capacity = other.capacity;
            currSize = other.currSize;
            delete[] data;
            data = new T[capacity];
            for (int i = 0; i < currSize; i++) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~MegaArray() 
    {
        delete[] data;
    }

    void display() const 
    {
        for (int i = 0; i < currSize; i++) 
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void add(T val) 
    {
       
        if (currSize == capacity) 
        {
            reSize();
        }
        data[currSize++] = val;
    }

    T remove() 
    {
        if (currSize == 0) 
        {
            throw std::out_of_range("MegaArray is empty");
        }
        T val = data[--currSize];
        if (currSize <= capacity / 2 && capacity > 10) 
        {
            capacity /= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < currSize; i++) 
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        return val;
    }

    int size() const 
    {
        return capacity;
    }

    T get(int index) 
    {
        if (index < 0 || index >= currSize) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](int index) 
    {
        if (index < 0 || index >= currSize) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
};

template<typename T>
void InsertionSort(MegaArray<T>& arr) 
{
    int n = arr.size();
    for (int i = 1; i < n; i++) 
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

template<typename T>
void MergeSort(MegaArray<T>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

template<typename T>
void Merge(MegaArray<T>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    MegaArray<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) 
    {
        L.add(arr[left + i]);
    }
    for (int j = 0; j < n2; j++) 
    {
        R.add(arr[mid + 1 + j]);
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


