//
// Created by marci on 14.01.2023.
//

#ifndef EX2_WAREHOUSE_H
#define EX2_WAREHOUSE_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class Warehouse {
private:
    string productName;
    int productAmount;
public:
    Warehouse(string productName, int productAmount);
    Warehouse();
    ~Warehouse();
    void show();

    const string &getProductName() const;

    void setProductName(const string &productName);

    const int getProductAmount();

    void setProductAmount(int productAmount);
};


#endif //EX2_WAREHOUSE_H
