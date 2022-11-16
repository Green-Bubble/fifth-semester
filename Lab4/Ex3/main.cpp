#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Citizen.h"
#include "City.h"

//------------------------START: KOD NIEWYMAGANY, DO UŁATWIENIA PRACY-----------------------------
string names[20] = {"Marek","Marcin","Janusz","Bohdan","Nikita","Robert","Kamil","Maciej"
                    ,"Adam","Bartek","Ewa","Anna","Irena","Alicja","Agata","Elzbieta",
                    "Daria","Natalia","Julia","Katarzyna"};
string surnames[20] = {"Kowalski","Krolikowski","Nowak","Scirka","Solarski","Milosz","Kapuscinski",
                       "Toporowski","Skic","Lopaciak","Glusiec","Pol","Baran","Niemiec",
                       "Wojcik","Wozniak","Czerniak","Szalak","Psiarski","Tararajko"};

string citiesNames[5] = {"Lublin","Swidnik","Biala Podlaska","Zamosc","Krasnik"};

Citizen generateRandomCitizen(int rangeOfPostalCodes){

    Citizen::Gender gender = static_cast<Citizen::Gender>(rand()%2);

    //Wykorzystanie faktu że w C++ enum może być używany jako int.
    string name = names[rand()%10+(10*gender)]; //Jeżeli gender = 0 to będzie wybierać pierwsze 10 imion (męskie), jak 1 to ostatnie 10 (żeńskie)

    string surname = surnames[rand()%20];

    int age = rand()%100+1;

    stringstream postalCodeStream;  //Użycie stringstream dla ułatwienia zachowania formatu poprawnego dla kodów pocztowych
    postalCodeStream << "21-"<<setw(3)<<setfill('0')<<rand()%rangeOfPostalCodes;    //setw(int) - minimalna szerokosc następnego ciągu, setfill(char) - znaki wypełniające jeżeli podany ciąg jest krótszy od setw()
    string postalCode = postalCodeStream.str(); //Konwersja na string

    return *(new Citizen(name,surname,age,gender,postalCode));
}

City generateRandomCity(){
    City city = *(new City(citiesNames[rand()%5]));
    int rangeOfPostalCodes = (rand()%100)+2;    //Określenie przedziału kodów pocztowych w danym mieście
    int citizensAmount = (rand()%100)+10;

    for(int i = 0; i < citizensAmount; i++){
        Citizen citizen = generateRandomCitizen(rangeOfPostalCodes);
        city.addCitizen(citizen);
    }

    return city;
}
//------------------------KONIEC: KOD NIEWYMAGANY, DO UŁATWIENIA PRACY-----------------------------

void showCities(vector<City> c){
    for(auto iterator = c.begin(); iterator != c.end();iterator++){
        (*iterator).showCity();
    }
}

void MostPostalCodesFunc(vector<City> c){
    City city = *(max_element(c.begin(),c.end(),[](City a, City b) {    //funckja max_element oczekuje predykatu porównującego dwie wartości, zwrócenie true oznacza że drugi argument predykatu jest "max" i z nim będą porównywane kolejne wartości
        return a.postalCodes(false) < b.postalCodes(false); //dlatego jest true jeśli drugie miasto ma więcej kodów
    }));

    cout<<"Najwiecej kodow pocztowych ma: ";
    city.showCity();
    auto temp = city.postalCodes(true);
    cout<<"Z wynikiem: "<<temp<<endl;
}

void LeastCitizensFunc(vector<City> c){
    City city = *(min_element(c.begin(),c.end(),[](City a, City b) {    //natomiast w min_element, jeżeli predykat zwróci true to do dalszych porównań wybrany zostanie argument 1 jako "min"
        return a.cityCitizens() < b.cityCitizens();
    }));

    cout<<"Najmniej mieszkancow ma: ";
    city.showCity();
    cout<<"Z wynikiem: "<<city.cityCitizens()<<endl;
}

//Enum dla większej czytelności
enum FindExtremesMode {MostPostalCodes,LeastCitizens};

void the_most(vector<City> c, FindExtremesMode mode){
    switch(mode){
        case MostPostalCodes: {
            MostPostalCodesFunc(c);
            break;
        }
        case LeastCitizens:
            LeastCitizensFunc(c);
            break;
    }
    cout<<endl;
}


void statatistic(vector<City> c){
    for_each(c.begin(),c.end(),[](City city){
        cout<<"\t\t";
        city.showCity();
        cout<<"Liczba mieszkancow: "<<city.cityCitizens()<<endl;
        cout<<city.cityCitizens()-city.women()<<" Mezczyzn i "<<city.women()<<" Kobiet"<<endl;
        cout<<city.adults()<<" Pelnoletnich i "<<city.cityCitizens()-city.adults()<<" Niepelnoletnich";
        cout<<endl<<endl;
    });
}

void sort_cities(vector <City> &c){
    sort(c.begin(),c.end(),[](City c1, City c2){    //Funkcja sort z predykatem, jeżeli zwraca true to oznacza że argumenty 1 i 2 są w odpowiedniej kolejności
       return c1.cityCitizens() < c2.cityCitizens();    //W tym wypadku oczekiwana jest kolejność rosnąca według liczby mieszkańców
    });
}

int main() {
    srand(time(NULL));  //Niezbędne do poprawnego działania rand()

    vector<City> cities;

    for(int i = 0; i < 5; i++){
        cities.push_back(generateRandomCity());
    }

    cout<<"--------------WYGENEROWANE MIASTA-------------------"<<endl;
    statatistic(cities);
    cout<<"--------------POSORTOWANE MIASTA-------------------"<<endl;
    sort_cities(cities);
    statatistic(cities);
    cout<<"--------------MIASTA Z EKSTREMAMI-------------------"<<endl;
    the_most(cities,LeastCitizens);
    the_most(cities,MostPostalCodes);
    cout<<"--------------PRZYKLADOWE UZYCIA-------------------"<<endl;
    cout<<"showCity(): "<<endl;
    cities[0].showCity();
    cout<<endl;

    cout<<"postalCodes(true): "<<endl;
    cities[0].postalCodes(true);
    cout<<endl;

    cout<<"showCitizens(): "<<endl;
    cities[0].showCitizens();
    cout<<endl;

    cout<<"deleteCitizen(surname,age): "<<endl;
    cout<<"Liczba mieszkancow przed usunieciem: "<<cities[0].cityCitizens()<<endl;
    cout<<"Podaj nazwisko i wiek osoby do usunięcia (nazwisko <ENTER> wiek): ";
    string surname;
    int age;
    cin>>surname>>age;
    cities[0].deleteCitizen(surname,age);
    cout<<"Liczba mieszkancow po usunieciu: "<<cities[0].cityCitizens()<<endl;

    cout<<endl;

    return 0;
}