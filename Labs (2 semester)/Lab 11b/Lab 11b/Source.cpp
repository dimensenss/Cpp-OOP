#include "Header.h"
figure::figure(const int& a, const int& b, const int& c ){
    this->a = a;
    this->b = b;
    this->c = c;
}
float figure::CalculateArea()
{
    if (b == 0 && c == 0) {
        float CircleArea = pi * pow(this->a, 2);
        return CircleArea;
    }
    /*else if (a == 0 && c == 0) {
        float CircleArea = pi * pow(this->b, 2);
        return CircleArea;
    }
    else if (a == 0 && b == 0) {
        float CircleArea = pi * pow(this->c, 2);
        return CircleArea;
    }*/
    else {
        float p = (a + b + c) / 2;
        double TriangleArea = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
        return TriangleArea;
    }
}