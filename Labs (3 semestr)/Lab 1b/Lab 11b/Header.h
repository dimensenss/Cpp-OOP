#pragma once
#include <iostream>
#include <conio.h>
#define pi 3.1415
using namespace std;
class figure {
    int a, b, c;
public:
    figure(const int& a = 0, const int& b = 0, const int& c = 0);
    float CalculateArea();
};