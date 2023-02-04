//
// Created by marcinskic on 10/6/22.
//

#ifndef LAB1_STUDENT_H
#define LAB1_STUDENT_H


#include <string>
#include <iostream>
#include "Person.h"

using namespace std;
class Student:public Person {
private:
    string index;
public:
    Student (string name, string surname, int age);
    Student();
    void setIndex(string index);
    string getIndex();
    void showInfoStudent();
};


#endif //LAB1_STUDENT_H
