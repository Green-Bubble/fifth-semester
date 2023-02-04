//
// Created by marcinskic on 10/27/22.
//

#ifndef EX2_DEVELOPER_H
#define EX2_DEVELOPER_H


#include "Employee.h"

class Developer : public Employee {
public:
    Developer(string surname,int age, int experience, float salary);
    Developer();
    virtual ~Developer();
    virtual float calculateBonus(int value) override;
    virtual void show() override;
};


#endif //EX2_DEVELOPER_H
