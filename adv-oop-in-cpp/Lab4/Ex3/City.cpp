//
// Created by marcinskic on 11/10/22.
//

#include "City.h"
#include <algorithm>
#include <iostream>
#include <map>

City::City(string cityName) {
    this->cityName = cityName;
}

void City::addCitizen(Citizen citizen) {
    citizens.push_back(citizen);
}

//Ta metoda znajdzie i usunie pierwszego mieszkańca na liście który spełnia ten warunek (nazwisko i wiek)
void City::deleteCitizen(string surname, int age) {
    auto iterator = find_if(citizens.begin(),citizens.end(),[surname,age](Citizen citizen){ //Lambda C++
        return citizen.getSurname() == surname && citizen.getAge() == age;
    });

    //Zabezpieczenie, jezeli nie ma takiego mieszkanca to funkcja find_if zwraca __last
    if(iterator != citizens.end()) {
        citizens.erase(iterator);
    }
}

//Ta metoda usuwa w sposób zaprojektowany z myślą o bibliotece STL ale usunie wszystkie wystąpienia mieszkańców o takim nazwisku i wieku a nie jednego
void City::deleteCitizens(std::string surname, int age) {
    auto removeIterator = remove_if(citizens.begin(),citizens.end(),[surname,age](Citizen citizen){
        return citizen.getSurname() == surname && citizen.getAge() == age;
    }); //remove i remove_if nie zmieniają wielkości tablicy ale zwracają iterator który jest na pozycji która powinna być nowym end() na podstawie liczby usuniętych elementów, więc...

    citizens.erase(removeIterator,citizens.end());  //... wystarczy wykasować wszystkie elementy które są za tym iteratorem
}

void City::showCitizens() {
    for_each(citizens.begin(),citizens.end(),[](Citizen citizen){
       citizen.show();
       cout<<endl;
    });
}

void City::showCity() {
    cout<<"Miasto: "<<cityName<<endl;
}

int City::women() {
    return filterCount([](Citizen citizen) {    //Jako argument zostaje przekazana lambda określająca czy dany mieszkaniec spełnia warunek zliczania
        return citizen.getGender() == citizen.Female;
    });
}

int City::cityCitizens() {
    return citizens.size();
}

int City::adults() {
    return filterCount([](Citizen citizen) {
        return citizen.getAge() >= 18;
    });
}

int City::postalCodes(bool doShowStatistic) {
    map<string,int> postalCodes;    //Zamiast tworzyć nową klasę lub strukturę, do tego zadania idealnie pasował kontener typu słownikowego: klucz - wartość

    for_each(citizens.begin(),citizens.end(),[&postalCodes](Citizen citizen){   //W lambdzie zostaje przekazana referencja do mapy ponieważ będziemy ją wypełniać danymi
        auto postalCode = citizen.getPostalCode();

        if(postalCodes.find(postalCode) != postalCodes.end()){  //Jeżeli taki kod pocztowy już został znaleziony to inkrementowana jest liczbę wystąpień
            postalCodes[postalCode]++;
        } else {    //A jeśli to pierwsze wystąpienie to zostaje stworzony klucz o wartości 1 (operator[] automatycznie tworzy klucz jeżeli nie istniał)
            postalCodes[postalCode] = 1;
        }
    });

    if(doShowStatistic){    //Wyświetlenie wszystkich kodów
        cout<<"Statystki kodow pocztowych: "<<endl;
        for_each(postalCodes.begin(),postalCodes.end(),[](pair<string,int> para){   //lambda przyjmująca jako argument obiekt typu pair
            cout<<para.first<<" -> "<<para.second<<" mieszkancow"<<endl;    //Zmienne dostępowe first -> klucz i second -> wartość
        });
    }

    return postalCodes.size();  //Zwrócenie wielkości mapy czyli defacto liczby unikatowych kluczy czyli kodów pocztowych
}

//Funkcja szablonowa która jako argument oczekuje funktora (predykata) jednoargumentowego na podstawie którego określone zostanie czy mieszkaniec o danych wartościach powinien być zliczany
template<typename UnaryPredicate>
int City::filterCount(UnaryPredicate Predicate) {
    return count_if(citizens.begin(),citizens.end(),Predicate);
}
