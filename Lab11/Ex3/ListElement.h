//
// Created by marci on 15.01.2023.
//

#ifndef EX3_LISTELEMENT_H
#define EX3_LISTELEMENT_H

#include <memory>
#include <iostream>

using namespace std;

class ListElement {
public:
    shared_ptr<ListElement> next;
    weak_ptr<ListElement> prev;

    ~ListElement() {
        cout<<"Destruktor elementu"<<endl;
    }
};


#endif //EX3_LISTELEMENT_H
