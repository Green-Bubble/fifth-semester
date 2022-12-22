//
// Created by marci on 16.12.2022.
//

#ifndef EX3_STUDENT_H
#define EX3_STUDENT_H

#include <string>
#include <iomanip>
#include <sstream>

class Student {
public:
    std::string name;
    std::string surname;
    char gender;
    int mark;
    std::string email;

    Student();
    Student(const std::string &name, const std::string &surname, char gender, int mark, const std::string &email);
    std::string getTableRow();
    std::string getCSV();
};


#endif //EX3_STUDENT_H
