#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
template <typename T>

class Array {
    T size, ind;
    T* arr;
public:
    Array(const T& ind = 0, const T& size = 100);
    void fill_arr(const T& n, const T& idx);
    void sum_arr();
    void average_arr();
    void print();
    T get_ind() { return ind; }
    T& operator[](const int& idx);
    T& operator()(const T& ind = 0, const T& size = 100);


    ~Array()
    {
        delete[] arr;
    }
};