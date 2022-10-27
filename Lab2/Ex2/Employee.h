//
// Created by marcinskic on 10/27/22.
//

#ifndef EX2_EMPLOYEE_H
#define EX2_EMPLOYEE_H
#include <string>

using namespace std;

class Employee {
private:
    string surname;
    int age;
    int experience;
    float salary;
public:
    Employee(string surname, int age, int experience, float salary);
    Employee();
    virtual ~Employee();
    virtual void show();
    virtual float calculateBonus(int value) = 0;
    int ageEmployment();

    const string &getSurname() const;

    int getAge() const;

    int getExperience() const;

    float getSalary() const;

};


#endif //EX2_EMPLOYEE_H
