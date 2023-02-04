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
#include <regex>
#include<limits>

#include "Student.h"


class StudentsFile {
private:
    std::string header = "imie;nazwisko;plec(KM);ocena;email";
    std::vector<Student> students;

public:
    //Metody ogólnego zastosowania, niepowiązane ściśle z tym zadaniem i jego typami zmiennych
    std::vector<std::string> split(std::string text,char delim);
    void clearInputStreamIfNextCharIsNotSpace();

    //Metody pomocnicze dla tego zadania
    bool readFromFile(std::fstream &file);
    void saveToFile(std::string path);
    void saveToFile(std::string path,std::vector<Student> students);
    void showHeader();
    void showStudents(std::vector<Student> students);

    //Metody stricte powiązane z opcjami dostępnymi dla użytkownika
    void showStudents();
    void addNewStudent();
    void showStudentsWithSurname();
    void createGenderFiles();
    void showSomeNumberOfStudents();
    void sortStudentsAscendingByMark();
};


#endif //EX3_STUDENTSFILE_H
