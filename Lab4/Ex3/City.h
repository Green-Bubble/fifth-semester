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

    template<typename UnaryPredicate>
    int filterCount(UnaryPredicate Predicate);
public:
    City(string cityName);
    void addCitizen(Citizen citizen);
    void deleteCitizen(string surname, int age);
    void showCitizens();
    void showCity();
    int women();
    int adults();
    int cityCitizens();
    int postalCodes(bool doShowStatistic);
};


#endif //EX3_CITY_H
