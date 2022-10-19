//
// Created by marci on 19.10.2022.
//

#include <iostream>
#include "Dog.h"

Dog::Dog() {

}

Dog::Dog(string name, string breed, int levelOfGuideSkills, int levelOfTrackerSkills, int limbNr, bool isProtected):Animal(name,limbNr,isProtected) {
    this->breed = breed;
    this->levelOfGuideSkills = levelOfGuideSkills;
    this->levelOfTrackerSkills = levelOfTrackerSkills;
}

Dog::Dog(string name, int limbNr, bool isProtected) : Animal(name, limbNr, isProtected) {

}

void Dog::setSkillLevel(Dog::Skill skill, int value) {
    switch(skill){
        case guideSkills:
            levelOfGuideSkills = value;
            break;
        case trackerSkills:
            levelOfTrackerSkills = value;
            break;
    }
}

int Dog::getSkillLevel(Dog::Skill skill) {
    switch(skill){
        case guideSkills:
            return levelOfGuideSkills;
        case trackerSkills:
            return levelOfTrackerSkills;
    }
}

void Dog::giveVoice() {
    cout<<"Hau, hau";
}

void Dog::info() {
    Animal::info();
    cout<<"Jest to pies o rasie "<<breed<<" o poziomach "<<levelOfGuideSkills<<" przewodnika i "<<levelOfTrackerSkills<<" tropienia"<<endl;
}
