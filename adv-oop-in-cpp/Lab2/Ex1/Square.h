//
// Created by marcinskic on 10/27/22.
//

#ifndef EX1_SQUARE_H
#define EX1_SQUARE_H
#include "Figure.h"

class Square : public Figure {
private:
    float a;
public:
    Square(float a);
    ~Square();
    virtual void calculateArea() override;
    virtual void calculatePerimeter() override;
    virtual void show() override;
};


#endif //EX1_SQUARE_H
