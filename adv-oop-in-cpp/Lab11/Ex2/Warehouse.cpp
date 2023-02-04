//
// Created by marci on 14.01.2023.
//


#include "Warehouse.h"

const string &Warehouse::getProductName() const {
    return productName;
}

void Warehouse::setProductName(const string &productName) {
    Warehouse::productName = productName;
}

const int Warehouse::getProductAmount() {
    return productAmount;
}

void Warehouse::setProductAmount(int productAmount) {
    Warehouse::productAmount = productAmount;
}

Warehouse::Warehouse(string productName, int productAmount) {
    Warehouse();
    this->productName = productName;
    this->productAmount = productAmount;
}

Warehouse::Warehouse() {
}

void Warehouse::show() {
    cout<<productName<<":"<<productAmount<<endl;
}

Warehouse::~Warehouse() {
    cout<<"Destruktor warehouse"<<endl;
}


