#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

void fill_array(int* a, int size); 
void print_array(int* a, int size);
void buble_sort(int* a, int s);
void sort_array(int* ,  int );

void alloc_matrix(int**& m, int size);
void release_matrix(int**& m, int size);

void fill_matrix(int** m, int size);
void print_matrix(int** m, int size);
void buble2_sort(int** m, int size);
void sort_matrix(int** m, int size);
