//
// Created by marcinskic on 10/27/22.
//

#ifndef EX1_FIGURE_H
#define EX1_FIGURE_H


class Figure {
private:
    float area;
protected:
    float perimeter;
public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area);
    void getPerimeter();
    virtual void calculateArea()=0;
    virtual void calculatePerimeter()=0;
    virtual void show();
};


#endif //EX1_FIGURE_H