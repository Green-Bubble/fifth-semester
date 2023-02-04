//
// Created by marcinskic on 10/27/22.
//

#include "TeamLeader.h"
#include <iostream>

using namespace std;

TeamLeader::TeamLeader(const string &surname, int age, int experience, float salary) : Employee(surname, age,
                                                                                                experience, salary) {}

TeamLeader::~TeamLeader() {

}

void TeamLeader::show() {
    cout<<"Jestem Team Leader z "<<getExperience()<<" letnim doswiadczeniem i bonusem: "<<calculateBonus(100)<<endl;
}

float TeamLeader::calculateBonus(int value) {
    return value*(1+getSalary()+getExperience());
}

