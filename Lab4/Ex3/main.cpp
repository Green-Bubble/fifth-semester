#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Citizen.h"
#include "City.h"

string names[20] = {"Marek","Marcin","Janusz","Bohdan","Nikita","Robert","Kamil","Maciej"
                    ,"Adam","Bartek","Ewa","Anna","Irena","Alicja","Agata","Elzbieta",
                    "Daria","Natalia","Julia","Katarzyna"};
string surnames[20] = {"Kowalski","Krolikowski","Nowak","Scirka","Solarski","Miłosz","Lach",
                       "Surtel","Skic","Łopaciak","Głusiec","Pol","Metod","Niemiec",
                       "Tusk","Burzuj","Czerniak","Szalak","Psiarski","Tararajko"};

Citizen generateRandomCitizen(){
    int surnameNumber = rand()%20;
    int age = rand()%100+1;
    stringstream postalCode;
    postalCode << "21-"<<setw(3)<<setfill('0')<<rand()%1000;

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

void showCities(vector<City> c){

}

void the_most(vector<City> c, int mode){

}

void statatistic(vector<City> c){

}

void sort_cities(vector <City> &c){

}
int main() {
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        generateRandomCitizen().show();
        cout<<endl;
    }

    return 0;
}