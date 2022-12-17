#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "StudentsFile.h"

int main() {
    StudentsFile studentsFile;
    std::fstream file;
    std::string path;

    while(true){
        std::cout<<"Podaj sciezke do pliku:";
        std::cin>>path;

        file.open(path);

        if(!file.is_open()){
            std::cout<<"Niepowodzenie otwierania pliku, sprobuj ponownie"<<std::endl;
            continue;
        }

        break;
    }

    studentsFile.readFromFile(file);

    while(true){
        char choice;
        fflush(stdin);

        std::cout<<"1 - Wyswietlenie ksiazki adresowej"<<std::endl;
        std::cout<<"2 - Dodaj nowa osobe"<<std::endl;
        std::cout<<"3 - Wyszukaj po nazwisku"<<std::endl;
        std::cout<<"4 - Wygeneruj pliki wedlug plci"<<std::endl;
        std::cout<<"5 - Wyswietl wybrana liczbe studentow"<<std::endl;
        std::cout<<"6 - Posortuj wedlug ocen rosnaco"<<std::endl;
        std::cout<<"7 - Opusc program"<<std::endl;

        std::cout<<"Twoj wybor:";
        std::cin>>choice;

        switch (choice) {
            case '1':
                studentsFile.showStudents();
                break;
            case '2':
                studentsFile.addNewStudent();
                break;
            case '7':
                studentsFile.saveToFile(path);
                return 0;
            default:
                std::cout<<"Nie istnieje opcja "<<choice<<std::endl;
        }

    }
}


