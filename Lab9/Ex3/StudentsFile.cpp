//
// Created by marci on 16.12.2022.
//

#include "StudentsFile.h"

std::string StudentsFile::capitalizeFirstLetter(std::string text) {
    return text.replace(0,1,std::string (1,toupper(text.at(0))));
}

bool StudentsFile::readFromFile(std::fstream &file) {

    std::string line = "";
    try{
        std::getline(file,line);

        if(line != header){
            std::cout<<"Niepoprawny format nazw kolumn wczytywanego pliku, kartoteka będzie pusta!"<<std::endl;
            return false;
        }
    } catch (...) {
        std::cout<<"Niepowodzenie wczytania nagłówka pliku, kartoteka będzie pusta!"<<std::endl;
        return false;
    }

    //Zakładam że dane zapisane w pliku są już zweryfikowane w trakcie podawania ich przez użytkownika
    while(std::getline(file,line)){
        std::stringstream lineStream;
        std::string temp;
        Student student;

        lineStream<<line;

        std::getline(lineStream,temp,';');
        student.name = temp;

        std::getline(lineStream,temp,';');
        student.surname = temp;

        std::getline(lineStream,temp,';');
        student.gender = temp.at(0);

        std::getline(lineStream,temp,';');
        student.mark = std::stoi(temp);

        std::getline(lineStream,temp,';');
        student.email = temp;

        std::cout<<student.getTableRow()<<std::endl;
    }

    return true;
}

void StudentsFile::showStudents() {

}

std::vector<std::string> StudentsFile::split(std::string text,char delim) {
    std::vector<std::string> split(std::count(text.begin(), text.end(),';')+1);
    std::stringstream stream;
    auto p = split.data();

    stream<<text;

    while(!stream.eof()){
        std::getline(stream,*p,delim);
        p++;
    }

    return split;
}
