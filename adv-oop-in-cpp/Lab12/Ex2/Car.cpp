//
// Created by marci on 15.01.2023.
//

#include <iostream>
#include "Car.h"

Car::Car(const string &model, int prodYear, float engineCapacity) : model(model), prodYear(prodYear),
                                                                    engineCapacity(engineCapacity) {

}

const string &Car::getModel() const {
    return model;
}

void Car::setModel(const string &model) {
    Car::model = model;
}

int Car::getProdYear() const {
    return prodYear;
}

void Car::setProdYear(int prodYear) {
    Car::prodYear = prodYear;
}

float Car::getEngineCapacity() const {
    return engineCapacity;
}

void Car::setEngineCapacity(float engineCapacity) {
    Car::engineCapacity = engineCapacity;
}

void Car::show() {
    cout<<"Model: "<<model<<" Rok produkcji: "<<prodYear<<" Pojemnosc silnika: "<<engineCapacity<<endl;
}
