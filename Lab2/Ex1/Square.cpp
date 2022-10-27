//
// Created by marcinskic on 10/27/22.
//

#include "Square.h"
#include <iostream>

using namespace std;


Square::Square(float a) : Figure() {
    this->a = a;
    cout<<"Konstruktor klasy Square"<<endl;
}

Square::~Square() {
    cout<<"Destruktor klasy Square"<<endl;
}

void Square::calculateArea() {
    float p=a*a;
    setArea(p);
}

void Square::show() {
    cout<<"Show w klasie Sqaure, pole: "<<getArea()<<endl;
}

void Square::calculatePerimeter() {
    perimeter = a*4;
}
