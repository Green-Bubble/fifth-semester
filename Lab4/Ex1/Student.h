//
// Created by marcinskic on 11/10/22.
//

#ifndef EX1_STUDENT_H
#define EX1_STUDENT_H


#include<iostream>
using namespace std;
class Student
{
private:
    int mark;
    string name;
public:
    Student(int mark, string name);
    int getMark();
};


#endif //EX1_STUDENT_H
