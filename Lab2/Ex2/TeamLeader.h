//
// Created by marcinskic on 10/27/22.
//

#ifndef EX2_TEAMLEADER_H
#define EX2_TEAMLEADER_H


#include "Employee.h"

class TeamLeader : public Employee{
public:
    TeamLeader(const string &surname, int age, int experience, float salary);
    TeamLeader();
    ~TeamLeader() override;

    void virtual show() override;
    float virtual calculateBonus(int value) override;

};


#endif //EX2_TEAMLEADER_H
