#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;
int main() {
    Figure *f1 = new Square(5);
    Figure *f2 = new Circle(3);
    f1->calculateArea();
    f1->calculatePerimeter();
    f1->show();
    f2->calculateArea();
    f2->calculatePerimeter();
    f2->show();
}