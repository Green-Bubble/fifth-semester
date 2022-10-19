//
// Created by marcinskic on 10/18/22.
//

#include <iostream>
#include "Animal.h"

int Animal::getLimbNr() {
    return limbNr;
}

void Animal::setLimbNr(int limbNr) {
    Animal::limbNr = limbNr;
}

const string Animal::getName() {
    return name;
}

void Animal::setName(string name) {
    Animal::name = name;
}

bool Animal::getIsProtected() {
    return isProtected;
}

void Animal::setIsProtected(bool isProtected) {
    Animal::isProtected = isProtected;
}

Animal::Animal() {
}

Animal::Animal(string name, int limbNr, bool isProtected) {
    this->name = name;
    this->limbNr = limbNr;
    this->isProtected = isProtected;
}

void Animal::giveVoice() {
    cout<<"Chrum, miau, hau, piiiii"<<endl;
}

void Animal::info() {
    cout<<"Zwierze "<<name<<" o "<<limbNr<<" konczynach, ktorego status ochrony jest "<<isProtected<<endl;
}
