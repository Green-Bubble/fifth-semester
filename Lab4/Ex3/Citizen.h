//
// Created by marcinskic on 11/10/22.
//

#ifndef EX3_CITIZEN_H
#define EX3_CITIZEN_H
#include <string>

using namespace std;
class Citizen {
public:
    enum Gender {Male, Female, Other};
private:
    string name;
    string surname;
    int age;
    Gender gender;
    string postalCode;
public:

    Citizen();
    Citizen(const string &name, const string &surname, int age, Gender gender, const string &postalCode);

    void show();

    const string &getName() const;

    const string &getSurname() const;

    int getAge() const;

    char getGender() const;

    const string &getPostalCode() const;
};


#endif //EX3_CITIZEN_H
