//
// Created by marcinskic on 1/19/23.
//

#include <iostream>
#include "Car.h"

Car::Car(const string &model, int prodYear, float engineCap) : model(model), prodYear(prodYear), engineCap(engineCap) {}

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

float Car::getEngineCap() const {
    return engineCap;
}

void Car::setEngineCap(float engineCap) {
    Car::engineCap = engineCap;
}

void Car::show() {
    cout<<"Model: "<<model<<" rok prod: "<<prodYear<<" pojemnosc silnika: "<<engineCap<<endl;
}
