#include <iostream>
#include "Shop.h"

int main() {

    vector<shared_ptr<Warehouse>> warehouses;
    warehouses.push_back(make_shared<Warehouse>("Ksiazka",120));
    warehouses.push_back(make_shared<Warehouse>("Komputer",40));
    warehouses.push_back(make_shared<Warehouse>("Lozko",30));
    warehouses.push_back(make_shared<Warehouse>("Telefon",100));



    vector<unique_ptr<Shop>> shops;

    shops.push_back(make_unique<Shop>("RTV EURO AGD"));
    shops[0]->addWarehouse(warehouses[1]);
    shops[0]->addWarehouse(warehouses[3]);

    shops.push_back(make_unique<Shop>("Biedronka"));
    shops[1]->addWarehouse(warehouses[0]);
    shops[1]->addWarehouse(warehouses[1]);
    shops[1]->addWarehouse(warehouses[2]);
    shops[1]->addWarehouse(warehouses[3]);

    shops.push_back(make_unique<Shop>("Empik"));
    shops[2]->addWarehouse(warehouses[0]);

    shops.push_back(make_unique<Shop>("IKEA"));
    shops[3]->addWarehouse(warehouses[2]);

    shops.push_back(make_unique<Shop>("X-kom"));
    shops[4]->addWarehouse(warehouses[1]);
    shops[4]->addWarehouse(warehouses[3]);

    cout<<"Sprzedaz w ";
    shops[0]->showName();
    cout<<"Stan na magazynie: "<<warehouses[1]->getProductAmount()<<" "<<warehouses[1]->getProductName()<<endl;
    shops[0]->tryToSell("Komputer",30);

    cout<<"Sprzedaz w ";
    shops[1]->showName();
    cout<<"Stan na magazynie: "<<warehouses[1]->getProductAmount()<<" "<<warehouses[1]->getProductName()<<endl;
    shops[1]->tryToSell("Komputer",20);

    cout<<"Sprzedaz w ";
    shops[4]->showName();
    cout<<"Stan na magazynie: "<<warehouses[1]->getProductAmount()<<" "<<warehouses[1]->getProductName()<<endl;
    shops[4]->tryToSell("Komputer",5);

    cout<<"Sprzedaz w ";
    shops[2]->showName();
    cout<<"Stan na magazynie: "<<warehouses[0]->getProductAmount()<<" "<<warehouses[0]->getProductName()<<endl;
    shops[2]->tryToSell("Ksiazka",100);

    cout<<"Sprzedaz w ";
    shops[1]->showName();
    cout<<"Stan na magazynie: "<<warehouses[0]->getProductAmount()<<" "<<warehouses[0]->getProductName()<<endl;
    shops[1]->tryToSell("Ksiazka",50);

    shops.clear();
    warehouses.clear();

    return 0;
}