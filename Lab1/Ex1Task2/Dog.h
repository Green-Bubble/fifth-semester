//
// Created by marci on 19.10.2022.
//

#ifndef EX1TASK2_DOG_H
#define EX1TASK2_DOG_H


#include "Animal.h"

class Dog : public Animal{
private:
    string breed;
    int levelOfGuideSkills = 0;
    int levelOfTrackerSkills = 0;
public:
    enum Skill {guideSkills,trackerSkills}; //Enum w celu zwiekszenia przejrzystosci kodu

    Dog();
    Dog(string name, string breed,int levelOfGuideSkills,int levelOfTrackerSkills,int limbNr=4,bool isProtected=false);
    Dog(string name, int limbNr=4,bool isProtected=false);  //Zakladam ze psy maja 4 konczyny i nie sa chronione

    void setSkillLevel(Skill skill,int value);
    int getSkillLevel(Skill skill);
    void giveVoice();
    void info();
};


#endif //EX1TASK2_DOG_H
