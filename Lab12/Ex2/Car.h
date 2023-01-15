//
// Created by marci on 15.01.2023.
//

#ifndef EX2_CAR_H
#define EX2_CAR_H

#include <string>

using namespace std;

class Car {
private:
    string model;
    int prodYear;
    float engineCapacity;
public:
    const string &getModel() const;

    void setModel(const string &model);

    int getProdYear() const;

    void setProdYear(int prodYear);

    float getEngineCapacity() const;

    void setEngineCapacity(float engineCapacity);

    Car(const string &model, int prodYear, float engineCapacity);

    void show();
};


#endif //EX2_CAR_H
