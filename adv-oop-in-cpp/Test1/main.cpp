#include <iostream>
#include "Pracownik.h"
#include "PracDydaktyczny.h"
#include "PracNaukowy.h"

void pracownicyPowyzej5Lat(Pracownik** array,int size){
    for(int i = 0; i<size;i++){
        if(array[i]->stazPracy() > 5){
            array[i]->wyswietl();
            std::cout<<std::endl;
        }
    }
}

void iluWiecejNizSrednia(Pracownik** array,int size){
    float average = 0;
    for(int i = 0; i<size;i++){
        average += array[i]->wyplata();
    }

    average /= size;

    for(int i = 0; i<size;i++){
        if(array[i]->wyplata() > average){
            array[i]->wyswietl();
            std::cout<<std::endl;
        }
    }
}

int main() {
    simpleDate _2022_05;
    _2022_05.year = 2022;
    _2022_05.month = 5;

    simpleDate _2005_07;
    _2005_07.year = 2005;
    _2005_07.month = 7;

    simpleDate _2012_07;
    _2012_07.year = 2012;
    _2012_07.month = 7;

    PracNaukowy* nauk1 = new PracNaukowy("Marek","Skic","Doktor",_2012_07,"pracownik naukowy",5000,75);
    PracDydaktyczny* nauk2 = new PracDydaktyczny("Kamil","Borsuk","Magister",_2022_05,"pracownik dydaktyczny",3000,50,60);
    PracDydaktyczny* nauk3 = new PracDydaktyczny("Tadeusz","Ryjek","Profesor",_2005_07,"pracownik dydaktyczny",6000,50,40);

    Pracownik** arr = new Pracownik * [3];

    arr[0] = nauk1;
    arr[1] = nauk2;
    arr[2] = nauk3;

    std::cout<<"Pracownicy "<<std::endl;
    nauk1->wyswietl();
    std::cout<<std::endl;
    nauk2->wyswietl();
    std::cout<<std::endl;
    nauk3->wyswietl();

    std::cout<<std::endl<<"Powyzej 5 lat"<<std::endl;
    pracownicyPowyzej5Lat(arr,3);
    std::cout<<"Wiecej niz srednia"<<std::endl;
    iluWiecejNizSrednia(arr,3);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
