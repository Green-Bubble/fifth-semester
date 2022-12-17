//
// Created by marci on 16.12.2022.
//

#include "StudentsFile.h"

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

        students.push_back(student);
    }

    file.close();
    return true;
}

void StudentsFile::showStudents() {
    auto columnNames = split(header,';');

    //NAGŁÓWEK
    std::for_each(columnNames.begin(), columnNames.end(),[](std::string name){
        std::transform(name.begin(), name.end(),name.begin(),::toupper);
       std::cout<<std::setfill('_')<<std::setw(20)<<name;
    });
    std::cout<<std::endl;

    std::for_each(students.begin(), students.end(),[](auto student){
        std::cout<<student.getTableRow()<< std::endl;
    });
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

void StudentsFile::saveToFile(std::string path) {
    std::fstream file(path);
}

void StudentsFile::addNewStudent() {
    Student student;

    std::string temp;

    std::regex firstCapital("^[A-Z][a-z]*$");
    std::regex email("^\\w*@\\w*\\.\\w*$");
    std::regex mark("^[2-5]$");

    while(true){
        std::cout<<"Podaj imie (lub wszystkie wartosci w odpowiedniej kolejnosci, oddzielone spacja):";
        std::cin>>temp;

        if(!std::regex_match(temp,firstCapital)){
            std::cout<<"To nie jest poprawne imie"<<std::endl;
            fflush(stdin);
            continue;
        }

        student.name = temp;
        break;
    }

    while(true){
        std::cout<<"Podaj nazwisko:";
        std::cin>>temp;

        if(!std::regex_match(temp,firstCapital)){
            std::cout<<"To nie jest poprawne nazwisko"<<std::endl;
            fflush(stdin);
            continue;
        }

        student.surname = temp;
        break;
    }

    while(true){
        char tempC;

        std::cout<<"Podaj plec (K/M):";
        std::cin>>tempC;

        if(tempC != 'K' && tempC != 'M'){
            std::cout<<"To nie jest poprawna plec"<<std::endl;
            fflush(stdin);
            continue;
        }

        student.gender = tempC;
        break;
    }

    while(true){
        char tempC;

        std::cout<<"Podaj ocene (2 do 5):";
        std::cin>>tempC;

        if(tempC < '2' || tempC > '5'){
            std::cout<<"To nie jest poprawna ocena"<<std::endl;
            fflush(stdin);
            continue;
        }

        student.mark = tempC-48;
        break;
    }

    while(true){
        std::cout<<"Podaj email:";
        std::cin>>temp;

        if(!std::regex_match(temp,email)){
            std::cout<<"To nie jest poprawny email"<<std::endl;
            fflush(stdin);
            continue;
        }

        student.email = temp;
        break;
    }

    students.push_back(student);
    std::cout<<std::endl;
}
