//
// Created by marcinskic on 11/10/22.
//

#ifndef EX3_CITY_H
#define EX3_CITY_H

#include <string>
#include <vector>
#include "Citizen.h"

using namespace std;
class City {
private:
    vector<Citizen> citizens;
    string cityName;

    template<typename UnaryPredicate>   //Funkcja prywatna na wewnętrzne potrzeby obiektów
    int filterCount(UnaryPredicate Predicate);
public:
    City(string cityName);
    void addCitizen(Citizen citizen);
    void deleteCitizen(string surname, int age);    //Usuwa pierwszy element spełniający warunek
    void deleteCitizens(string surname, int age);   //Usuwa wszystkie elementy spełniające warunek
    void showCitizens();
    void showCity();
    int women();
    int adults();
    int cityCitizens();
    int postalCodes(bool doShowStatistic);  //Argument bool żeby nie wyświetlać zawsze wszystkich kodów pocztowych przy zliczaniu ich ilości
};


#endif //EX3_CITY_H
