//
// Created by marcinskic on 1/19/23.
//

#include "ExG3B.h"

void ExG3B::saveToFile() {
    regex nameR("^[A-Z][a-z]*$");
    regex surnameR("^[A-Z][a-z]*(\\-[A-Z][a-z]*)?$");
    regex ageR("^[0-9][0-9]?$");
    regex telephoneNumberR("^[1-9][0-9]{8}$");
    regex emailR("^[A-Za-z][A-Za-z0-9_\\-.]*@[A-Za-z0-9]+\\.[A-Za-z0-9]+$");

    string name;
    string surname;
    string age;
    string telephoneNumber;
    string email;

    while(true){
        cout<<"Podaj imie: "<<endl;
        cin>>name;

        if(!regex_match(name,nameR)){
            cout<<"Niepoprawne imie"<<endl;
            continue;
        }

        break;
    }

    while(true){
        cout<<"Podaj nazwisko: "<<endl;
        cin>>surname;

        if(!regex_match(surname,surnameR)){
            cout<<"Niepoprawne nazwisko"<<endl;
            continue;
        }

        break;
    }

    while(true){
        cout<<"Podaj wiek: "<<endl;
        cin>>age;

        if(!regex_match(age,ageR)){
            cout<<"Niepoprawny wiek"<<endl;
            continue;
        }

        break;
    }

    while(true){
        cout<<"Podaj number telefonu: "<<endl;
        cin>>telephoneNumber;

        if(!regex_match(telephoneNumber,telephoneNumberR)){
            cout<<"Niepoprawny numer telefonu"<<endl;
            continue;
        }

        break;
    }

    while(true) {
        cout << "Podaj email: " << endl;
        cin >> email;

        if (!regex_match(email, emailR)) {
            cout << "Niepoprawny email" << endl;
            continue;
        }

        break;
    }

    std::fstream file;

    file.open("users.csv",ios::app);

    if(!file.is_open()){
        cout<<"Niepowodzenie otwierania pliku"<<endl;
        return;
    }

    file<<name<<";"<<surname<<";"<<age<<";"<<telephoneNumber<<";"<<email<<endl;

    file.close();
}
