//
// Created by marcinskic on 10/6/22.
//

#include "Student.h"

Student::Student(string name, string surname, int age):Person(name,surname,age) {
    cout<<"Kontruktor klasy Student"<<endl;
}

Student::Student() {
    cout<<"Konstruktor bez. klasy Student"<<endl;
}

void Student::setIndex(string index) {
    this->index = index;
}

string Student::getIndex() {
    return index;
}

void Student::showInfoStudent() {
    showInfoPerson();
    cout<<"Index studenta: "<<index<<endl;
}