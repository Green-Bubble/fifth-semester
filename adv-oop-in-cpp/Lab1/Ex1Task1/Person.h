//
// Created by marcinskic on 10/6/22.
//

#ifndef LAB1_PERSON_H
#define LAB1_PERSON_H
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string surname;
    int age;
public:
    void init(string name,string surname,int age);
    Person(string name,string surname,int age);
    Person();
    void setAge(int age);
    string getSurname();
    bool is_18();
    void showInfoPerson();
};


#endif //LAB1_PERSON_H
