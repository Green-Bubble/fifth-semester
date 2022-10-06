//
// Created by marcinskic on 10/6/22.
//

#include<iostream>
#include "Person.h"

using namespace std;
Person::Person(string name, string surname,int age){
    this->name = name;
    this->surname = surname;
    this->age = age;
    cout<<"Konstruktor klasy bazowej - Person"<<endl;
}

Person::Person() {
    cout<<"Konstruktor bez argumentow klasy bazowej - Person"<<endl;
}

void Person::setAge(int age) {
    this->age = age;
}

string Person::getSurname() {
    return surname;
}

bool Person::is_18(){
    return age>=18;
}

void Person::showInfoPerson() {
    cout<<"Imie: "<<name<<" nazwisko: "<<surname<<" wiek: "<<age<<endl;
}

void Person::init(string name, string surname, int age) {
    this->name = name;
    this->surname= surname;
    this->age=age;
}
