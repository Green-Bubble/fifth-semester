//
// Created by marcinskic on 11/10/22.
//

#include "City.h"
#include <algorithm>
#include <iostream>

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

    /*remove_if(citizens.begin(),citizens.end(),[surname,age](Citizen citizen){
        return citizen.getSurname() == surname && citizen.getAge() == age;
    });*/
}

void City::showCitizens() {
    for_each(citizens.begin(),citizens.end(),[](Citizen citizen){
       citizen.show();
       cout<<endl;
    });
}

void City::showCity() {

}

int City::women() {
    return 0;
}

int City::cityCitizens() {
    return 0;
}

int City::adults() {
    return 0;
}

void City::postalCodes() {

}
