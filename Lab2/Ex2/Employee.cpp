//
// Created by marcinskic on 10/27/22.
//

#include "Employee.h"
#include <iostream>

Employee::Employee(string surname, int age, int experience, float salary) {
    this->surname = surname;
    this->age = age;
    this->experience = experience;
    this->salary = salary;
}

Employee::Employee() {

}

Employee::~Employee() {

}

void Employee::show() {
    cout<<"Dane: "<<surname<<" wiek "<<age<<" doswiadczenie "<<experience<<" zarobek "<<salary;
}

int Employee::ageEmployment() {
    return age-experience;
}

const string &Employee::getSurname() const {
    return surname;
}

int Employee::getAge() const {
    return age;
}

int Employee::getExperience() const {
    return experience;
}

float Employee::getSalary() const {
    return salary;
}


