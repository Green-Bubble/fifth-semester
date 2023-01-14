//
// Created by marci on 14.01.2023.
//

#ifndef EX2_SHOP_H
#define EX2_SHOP_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Warehouse.h"

using namespace std;

class Shop {
private:
    string name;
    vector<shared_ptr<Warehouse>> warehouses;
public:
    Shop(string name);
    ~Shop();
    void addWarehouse(shared_ptr<Warehouse> warehouse);
    bool tryToSell(string productName,int amount);
    void showUsedWarehouses();
    void showName();
};


#endif //EX2_SHOP_H
