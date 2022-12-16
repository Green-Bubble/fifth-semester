//
// Created by marci on 16.12.2022.
//

#ifndef EX3_STUDENTSFILE_H
#define EX3_STUDENTSFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>

#include "Student.h"


class StudentsFile {
private:
    std::string header = "imie;nazwisko;plec(KM);ocena;email";
    std::vector<Student> students;


public:
    std::string capitalizeFirstLetter(std::string text);
    std::vector<std::string> split(std::string text,char delim);


    bool readFromFile(std::fstream &file);
    void showStudents();
};


#endif //EX3_STUDENTSFILE_H
