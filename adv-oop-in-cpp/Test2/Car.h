//
// Created by marcinskic on 1/19/23.
//

#ifndef TEST2_CAR_H
#define TEST2_CAR_H

#include <string>

using namespace std;

class Car {
private:
    string model;
    int prodYear;
    float engineCap;
public:
    Car(const string &model, int prodYear, float engineCap);

    const string &getModel() const;

    void setModel(const string &model);

    int getProdYear() const;

    void setProdYear(int prodYear);

    float getEngineCap() const;

    void setEngineCap(float engineCap);

    void show();
};


#endif //TEST2_CAR_H
