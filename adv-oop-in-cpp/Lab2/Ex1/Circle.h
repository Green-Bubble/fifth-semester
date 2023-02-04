//
// Created by marcinskic on 10/27/22.
//

#ifndef EX1_CIRCLE_H
#define EX1_CIRCLE_H
#include "Figure.h"

class Circle : public Figure{
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;
    virtual void calculatePerimeter() override;
};


#endif //EX1_CIRCLE_H
