//
// Created by marci on 16.12.2022.
//

#include "StudentsFile.h"

bool StudentsFile::readFromFile(std::fstream &file) {

    std::string line = "";
    try{
        std::getline(file,line);

        if(line != header){
            std::cout<<"Niepoprawny format nazw kolumn wczytywanego pliku, kartoteka bedzie pusta!"<<std::endl;
            return false;
        }
    } catch (...) {
        std::cout<<"Niepowodzenie wczytania nagłówka pliku, kartoteka bedzie pusta!"<<std::endl;
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

void StudentsFile::showHeader() {
    auto columnNames = split(header,';');

    std::for_each(columnNames.begin(), columnNames.end(),[](std::string name){
        fflush(stdout);

        std::transform(name.begin(), name.end(),name.begin(),::toupper);
        std::cout<<std::setfill('_')<<std::setw(20)<<name;
    });
    std::cout<<std::endl;
}

void StudentsFile::showStudents() {
    showStudents(this->students);
}

void StudentsFile::showStudents(std::vector<Student> students) {
    showHeader();

    std::for_each(students.begin(), students.end(),[](auto student){
        std::cout<<student.getTableRow()<< std::endl;
    });
}

void StudentsFile::saveToFile(std::string path) {
    saveToFile(path,this->students);
}

void StudentsFile::saveToFile(std::string path,std::vector<Student> students) {
    std::ofstream file(path);

    file<<header<<std::endl;
    std::for_each(students.begin(), students.end(),[&](Student student){
        file<<student.getCSV()<<std::endl;
    });

    file.close();
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

    clearInputStreamIfNextCharIsNotSpace(); //Nie czyszczę stdin co każde wprowadzenie żeby umożliwić hurtowe wpisanie
                                            //wszystkich informacji oddzielonych spacjami
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

    clearInputStreamIfNextCharIsNotSpace();

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

void StudentsFile::clearInputStreamIfNextCharIsNotSpace() {
    if(std::cin.peek() != ' '){
        fflush(stdin);
    }
}

void StudentsFile::showStudentsWithSurname() {
    std::string searchedSurname;
    bool foundAny = false;
    std::vector<Student>::iterator foundStudent;

    while(!foundAny){

        std::cout<<"Podaj nazwisko studentow ktorych chcesz znalezc:";
        std::cin >> searchedSurname;

        foundStudent = std::find_if(students.begin(), students.end(),[&](Student student){
            return student.surname == searchedSurname;
        });

        foundAny = foundStudent != students.end();

        if(!foundAny){
            std::cout<<"Nie ma studenta o nazwisku: "<<searchedSurname<<", sprobuj jeszcze raz"<<std::endl;
        }
    }

    showHeader();

    do{
        std::cout<<(*foundStudent).getTableRow()<<std::endl;

        foundStudent = std::find_if(foundStudent+1, students.end(),[&](Student student){
            return student.surname == searchedSurname;
        });
    }while(foundStudent != students.end());
}

void StudentsFile::createGenderFiles() {
    std::ofstream kFile("k.csv");
    std::ofstream mFile("m.csv");

    kFile<<header<<std::endl;
    mFile<<header<<std::endl;

    std::for_each(students.begin(), students.end(),[&](Student student){
        if(student.gender == 'K'){
            kFile<<student.getCSV()<<std::endl;
        } else {
            mFile<<student.getCSV()<<std::endl;
        }
    });
}

void StudentsFile::showSomeNumberOfStudents() {
    int studentsCount;
    while(true){

        std::cout<<"Podaj liczbe studentow do wyswietlenia: ";

        if(!(std::cin>>studentsCount)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Prosze podac liczbe!"<<std::endl;
            continue;
        }

        if(studentsCount > students.size()){
            std::cout<<"Podano liczbe: "<<studentsCount<<" ktora jest wieksza niz liczba studentow: "<<students.size()<<", wyswietleni zostali wszyscy"<<std::endl;
            studentsCount = students.size();
        }

        break;
    }

    std::vector<Student> studentsToShow(students.begin(),students.begin()+studentsCount);

    showStudents(studentsToShow);

    fflush(stdin);
}

void StudentsFile::sortStudentsAscendingByMark() {
    std::sort(students.begin(), students.end(),[](Student a,Student b){
        return a.mark < b.mark;
    });
    std::cout<<"Posortowano!"<<std::endl;
}




