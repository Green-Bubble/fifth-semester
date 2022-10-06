//
// Created by marcinskic on 10/6/22.
//

#ifndef LAB1_TEACHER_H
#define LAB1_TEACHER_H
#include "Person.h"
using namespace std;

class Teacher: public Person {
private:
    int experience;
    string title;
public:
    Teacher(string name, string surname, int age, int experience,string title);
    Teacher();
    void setTitle(string title);
    int getExperience();
    bool is_Phd();
    void showInfoTeacher();
};


#endif //LAB1_TEACHER_H
