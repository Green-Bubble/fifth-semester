//
// Created by marci on 16.12.2022.
//

#include "Student.h"
Student::Student(const std::string &name, const std::string &surname, char gender, int mark, const std::string &email)
        : name(name), surname(surname), gender(gender), mark(mark), email(email) {}

Student::Student() {}

std::string Student::getTableRow() {
    std::stringstream row;
    row     <<std::setfill('_')
            <<std::setw(20)<<name
            <<std::setw(20)<<surname
            <<std::setw(20)<<gender
            <<std::setw(20)<<mark
            <<std::setw(20)<<email;
    return row.str();
}
