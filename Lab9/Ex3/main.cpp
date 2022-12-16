#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "StudentsFile.h"

int main() {
    StudentsFile studentsFile;
    std::fstream file;

    while(true){
        std::string path;
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

    auto cus = studentsFile.split("imie;nazwisko;plec(KM);ocena;email",';');

    std::for_each(cus.begin(), cus.end(),[](auto el){
        std::cout<<el<<" ";
    });
    std::cout<<std::endl;

    std::cout<<"1 - Wyswietlenie ksiazki adresowej"<<std::endl;
    std::cout<<"2 - Dodaj nowa osobe"<<std::endl;

    return 0;
}


