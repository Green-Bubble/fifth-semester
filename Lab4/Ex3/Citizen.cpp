//
// Created by marcinskic on 11/10/22.
//

#include "Citizen.h"
#include <iostream>

using namespace std;

Citizen::Citizen() {

}

Citizen::Citizen(const string &name, const string &surname, int age, Gender gender, const string &postalCode) : name(
        name), surname(surname), age(age), gender(gender), postalCode(postalCode) {}

void Citizen::show() {
    string genderStr = "";
    switch(gender){
        case Male:
            genderStr = "Male";
            break;
        case Female:
            genderStr = "Female";
            break;
        case Other:
            genderStr = "Other";
            break;
    }
    cout<<"Citizen: "<<name<<" "<<surname<<" "<<age<<"y/o, gender: "<<genderStr<<" living at: "<<postalCode<<" postalCode";
}

const string &Citizen::getName() const {
    return name;
}

const string &Citizen::getSurname() const {
    return surname;
}

int Citizen::getAge() const {
    return age;
}

char Citizen::getGender() const {
    return gender;
}

const string &Citizen::getPostalCode() const {
    return postalCode;
}
