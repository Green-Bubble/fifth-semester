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

void City::deleteCitizen(string surname, int age) {
    auto iterator = find_if(citizens.begin(),citizens.end(),[surname,age](Citizen citizen){
        return citizen.getSurname() == surname && citizen.getAge() == age;
    });

    if(iterator != citizens.end()) {
        citizens.erase(iterator);
    }
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
    return filterCount([](Citizen citizen) {
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
    map<string,int> postalCodes;


    for_each(citizens.begin(),citizens.end(),[&postalCodes](Citizen citizen){
        auto postalCode = citizen.getPostalCode();

        if(postalCodes.find(postalCode) != postalCodes.end()){
            postalCodes[postalCode]++;
        } else {
            postalCodes[postalCode] = 1;
        }
    });

    if(doShowStatistic){
        cout<<"Statystki kodów pocztowych: "<<endl;
        for_each(postalCodes.begin(),postalCodes.end(),[](pair<string,int> para){
            cout<<para.first<<" -> "<<para.second<<" mieszkancow"<<endl;
        });
    }

    return postalCodes.size();
}

template<typename UnaryPredicate>
int City::filterCount(UnaryPredicate Predicate) {
    return count_if(citizens.begin(),citizens.end(),Predicate);
}
