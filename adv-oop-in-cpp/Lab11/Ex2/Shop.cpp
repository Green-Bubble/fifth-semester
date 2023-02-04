//
// Created by marci on 14.01.2023.
//

#include "Shop.h"

Shop::Shop(string name) {
    this->name = name;
    //warehouses = vector<shared_ptr<Warehouse>>();
}

void Shop::addWarehouse(shared_ptr<Warehouse> warehouse) {
    warehouses.push_back(warehouse);
}

bool Shop::tryToSell(string productName, int amount) {
    auto warehouseIterator = find_if(warehouses.begin(),warehouses.end(),[&](shared_ptr<Warehouse> warehouse){
        return warehouse->getProductName() == productName && warehouse->getProductAmount() >= amount;
    });

    if(warehouseIterator != warehouses.end()){
        (*warehouseIterator)->setProductAmount((*warehouseIterator)->getProductAmount()-amount);
        cout<<"Zakupiono "<<amount<<" "<<productName<<endl;
        return true;
    } else {
        cout<<"Nie zakupiono "<<amount<<" "<<productName<<endl;
        return false;
    }
}

void Shop::showUsedWarehouses() {
    cout<<"Wykorzystywane magazyny: "<<endl;
    std::for_each(warehouses.begin(), warehouses.end(),[](auto warehouse){
        cout<<(warehouse->getProductName())<<" = "<<(warehouse->getProductAmount());
    });
}

void Shop::showName() {
    cout<<"Sklep: "<<name<<endl;
}

Shop::~Shop() {
    warehouses.clear();
    cout<<"Destruktor shop"<<endl;
}
