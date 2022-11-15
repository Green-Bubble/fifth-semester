#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Citizen.h"
#include "City.h"

string names[20] = {"Marek","Marcin","Janusz","Bohdan","Nikita","Robert","Kamil","Maciej"
                    ,"Adam","Bartek","Ewa","Anna","Irena","Alicja","Agata","Elzbieta",
                    "Daria","Natalia","Julia","Katarzyna"};
string surnames[20] = {"Kowalski","Krolikowski","Nowak","Scirka","Solarski","Miłosz","Lach",
                       "Surtel","Skic","Łopaciak","Głusiec","Pol","Metod","Niemiec",
                       "Tusk","Burzuj","Czerniak","Szalak","Psiarski","Tararajko"};

string citiesNames[5] = {"Lublin","Swidnik","Biala Podlaska","Zamosc","Krasnik"};

enum FindExtremesMode {MostPostalCodes,LeastCitizens};

Citizen generateRandomCitizen(int rangeOfPostalCodes){
    int surnameNumber = rand()%20;
    int age = rand()%100+1;
    stringstream postalCode;
    postalCode << "21-"<<setw(3)<<setfill('0')<<rand()%rangeOfPostalCodes;

    int genderNumber = rand()%100;
    if(genderNumber == 0){
        int nameNumber = rand()%20;
        return *(new Citizen(names[nameNumber],surnames[surnameNumber],age,Citizen::Other,postalCode.str()));
    } else if(genderNumber < 50){
        int nameNumber = rand()%10;
        return *(new Citizen(names[nameNumber],surnames[surnameNumber],age,Citizen::Male,postalCode.str()));
    } else {
        int nameNumber = rand()%10+10;
        return *(new Citizen(names[nameNumber],surnames[surnameNumber],age,Citizen::Female,postalCode.str()));
    }
}

City generateRandomCity(){
    City city = *(new City(citiesNames[rand()%5]));
    int rangeOfPostalCodes = (rand()%990)+10;
    int citizensAmount = (rand()%99900)+100;

    for(int i = 0; i < citizensAmount; i++){
        Citizen citizen = generateRandomCitizen(rangeOfPostalCodes);
        city.addCitizen(citizen);
    }

    return city;
}

void showCities(vector<City> c){
    for(auto iterator = c.begin(); iterator != c.end();iterator++){
        (*iterator).showCity();
    }
}

template <typename UnaryPredicate>
City findExtremeCity(vector<City> c,UnaryPredicate Predicate){
    return *(max_element(c.begin(),c.end(),Predicate));
}

void the_most(vector<City> c, FindExtremesMode mode){
    switch(mode){
        case MostPostalCodes: {
            City city = findExtremeCity(c, [](City a, City b) {
                return a.postalCodes(false) < b.postalCodes(false);
            });
            cout<<"Najwiecej znaczkow pocztowych ma: ";
            city.showCity();
            cout<<"Z wynikiem: "<<city.postalCodes(false)<<endl;
            break;
        }
        case LeastCitizens:
            City city = findExtremeCity(c, [](City a, City b) {
                return a.cityCitizens() > b.cityCitizens();
            });
            cout<<"Najmniej mieszkancow ma: ";
            city.showCity();
            cout<<"Z wynikiem: "<<city.cityCitizens()<<endl;
            break;
    }
}


void statatistic(vector<City> c){

}

void sort_cities(vector <City> &c){

}
int main() {
    srand(time(NULL));


    vector<City> cities;

    for(int i = 0; i < 10; i++){
        cities.push_back(generateRandomCity());
    }

    cities[0].showCitizens();
    cout<<"Liczba kobiet: "<<cities[0].women()<<endl;
    cout<<"Liczba dorosłych: "<<cities[0].adults()<<endl;

    /*cout<<"Podaj nazwisko i wiek osoby do usunięcia: ";
    string surname;
    int age;
    cin>>surname>>age;
    city.deleteCitizen(surname,age);
    city.showCitizens();
    cout<<"Liczba kobiet: "<<city.women()<<endl;
    cout<<"Liczba dorosłych: "<<city.adults()<<endl;*/
    cities[0].postalCodes(true);
    showCities(cities);
    for_each(cities.begin(),cities.end(),[](City city) {
        city.showCity();
        cout<<"Posiada tyle mieszkancow: "<<city.cityCitizens()<<endl;
    });
    cout<<"A najwiecej kodow posiada: "<<endl;
    the_most(cities,LeastCitizens);

    return 0;
}