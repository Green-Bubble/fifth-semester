//
// Created by marci on 23.10.2022.
//

#include <iostream>
#include "Cat.h"
using namespace std;

int Cat::getLevelOfMouseHunting() {
    return levelOfMouseHunting;
}

void Cat::setLevelOfMouseHunting(int levelOfMouseHunting) {
    Cat::levelOfMouseHunting = levelOfMouseHunting;
}

Cat::Cat(string name, int limbNr, bool isProtected) : Animal(name, limbNr, isProtected) {

}

Cat::Cat() {

}

void Cat::initMice(int mice[5]) {
    for(int i = 0; i < 5; i++){
        this->mice[i] = mice[i];
    }
}

void Cat::initCat(int levelOfMouseHunting, int *mice) {
    this->levelOfMouseHunting = levelOfMouseHunting;
    initMice(mice);
}

int Cat::getMice(int index) {
    return this->mice[index];
}

void Cat::giveVoice() {
    cout<<"Miau miau"<<endl;
}

void Cat::info() {
    Animal::info();
    cout<<"Jest to koteczek o "<<levelOfMouseHunting<<" poziomie lowienia myszy, ktory na przestrzeni 5 lat upolowal (zaczynajac od tego roku): [";
    for(int i = 0; i < 5; i++){
        if(i < 5-1){
            cout<<mice[i]<<", ";
        } else {
            cout<<mice[i];
        }
    }
    cout<<"] myszy"<<endl;
}
