//
// Created by marcinskic on 10/27/22.
//

#include "Developer.h"
#include <iostream>

using namespace std;

Developer::Developer(string surname, int age, int experience, float salary) : Employee(surname, age, experience,
                                                                                       salary) {

}

Developer::Developer() {

}

Developer::~Developer() {

}

float Developer::calculateBonus(int value) {
    return value+0.2*value*(getSalary()+getExperience());
}

void Developer::show() {
    Employee::show();
}

