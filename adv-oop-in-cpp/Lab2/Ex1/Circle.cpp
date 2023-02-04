//
// Created by marcinskic on 10/27/22.
//

#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(float r):Figure() {
    this->r = r;
    cout<<"Konstruktor w klasie Circle"<<endl;
}

Circle::~Circle() {
    cout<<"Destruktor w klasie Circle"<<endl;
}

void Circle::calculateArea() {
    float p=3.14*r*r;
    setArea(p);
}

void Circle::calculatePerimeter() {
    perimeter = 2*3.14*r;
}
