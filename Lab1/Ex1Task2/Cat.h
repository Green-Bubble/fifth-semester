//
// Created by marci on 23.10.2022.
//

#ifndef EX1TASK2_CAT_H
#define EX1TASK2_CAT_H


#include "Animal.h"
#include <string.h>

using namespace std;


class Cat : public Animal {
private:
    int levelOfMouseHunting;
    int mice[5];
public:
    Cat(string name,int limbNr=4,bool isProtected=false);    //Zakladam ze koty maja 4 konczyny i nie sa chronione
    Cat();
    void initMice(int mice[5]);
    void initCat(int levelOfMouseHunting,int mice[5]);
    int getLevelOfMouseHunting();
    void setLevelOfMouseHunting(int levelOfMouseHunting);
    int getMice(int index);
    void giveVoice();
    void info();
};


#endif //EX1TASK2_CAT_H
