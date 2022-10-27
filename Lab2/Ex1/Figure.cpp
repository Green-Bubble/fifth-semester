//
// Created by marcinskic on 10/27/22.
//

#include <iostream>
#include "Figure.h"

using namespace std;
Figure::Figure() {
    cout<<"Konstruktor klasy bazowej Figure"<<endl;
}

Figure::~Figure() {
    cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;
}

float Figure::getArea() {
    return area;
}

void Figure::setArea(float area) {
    this->area = area;
}

void Figure::show() {
    cout<<"Pole: "<<area<<", obwod: "<<perimeter<<endl;
}

void Figure::getPerimeter() {
    return getPerimeter();
}
