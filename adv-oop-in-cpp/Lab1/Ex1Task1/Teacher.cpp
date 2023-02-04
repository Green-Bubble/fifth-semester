//
// Created by marcinskic on 10/6/22.
//

#include <iostream>
#include "Teacher.h"
using namespace std;

Teacher::Teacher(string name, string surname, int age, int experience, string title):Person(name,surname,age) {
    this->experience = experience;
    this->title = title;
    cout<<"Konstruktor klasy Teacher"<<endl;
}

Teacher::Teacher() {
    cout<<"Konstruktor klasy Teacher bez argumentów"<<endl;
}

void Teacher::setTitle(string title) {
    this->title = title;
}

int Teacher::getExperience() {
    return experience;
}

bool Teacher::is_Phd() {
    return title=="Phd";
}

void Teacher::showInfoTeacher() {
    showInfoPerson();
    cout<<"Staz pracy: "<<experience<<" tytul naukowy:"<<title<<endl;
}
