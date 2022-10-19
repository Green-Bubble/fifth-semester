//
// Created by marcinskic on 10/18/22.
//

#ifndef EX1TASK2_ANIMAL_H
#define EX1TASK2_ANIMAL_H

#include <string>

using namespace std;

class Animal {
private:
    int limbNr;
    string name;
    bool isProtected;
public:
    Animal();
    Animal(string name,int limbNr,bool isProtected=true);

    int getLimbNr();

    void setLimbNr(int limbNr);

    const string getName();

    void setName(string name);

    bool getIsProtected();

    void setIsProtected(bool isProtected);

    void giveVoice();

    void info();

};


#endif //EX1TASK2_ANIMAL_H
