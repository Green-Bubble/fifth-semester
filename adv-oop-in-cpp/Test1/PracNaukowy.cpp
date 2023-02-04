//
// Created by marcinskic on 12/15/22.
//

#include <iostream>
#include "PracNaukowy.h"

PracNaukowy::PracNaukowy(const std::string &imie, const std::string &nazwisko, const std::string &tytul,
                         const simpleDate &dataZatrudnienia, const std::string &stanowisko, float pensjaZasadnicza,
                         int punktyPublikacyjne) : Pracownik(imie, nazwisko, tytul, dataZatrudnienia, stanowisko,
                                                             pensjaZasadnicza),
                                                   punktyPublikacyjne(punktyPublikacyjne) {}

PracNaukowy::PracNaukowy() {

}

std::string PracNaukowy::kategoria() {
    if(punktyPublikacyjne < 60){
        return "C";
    } else if(punktyPublikacyjne < 80){
        return "B";
    } else if(punktyPublikacyjne < 100){
        return "B+";
    } else if(punktyPublikacyjne < 110){
        return "A";
    } else {
        return "A+";
    }
}

PracNaukowy::~PracNaukowy() {

}

float PracNaukowy::wyplata() {
    float result = getPensjaZasadnicza();

    if(punktyPublikacyjne < 60){
        result *= 0.8;
    } else if(punktyPublikacyjne < 80){
        result *= 1;
    } else if(punktyPublikacyjne < 100){
        result *= 1.2;
    } else if(punktyPublikacyjne < 110){
        result *= 1.5;
    } else {
        result *= 2;
    }

    if(stazPracy() > 5){
        result += ((getPensjaZasadnicza()*3)/100)*(stazPracy()-5);
    }

    return result;
}

void PracNaukowy::wyswietl() {
    Pracownik::wyswietl();
    std::cout<<std::endl;
    std::cout<<"Jako pracownik naukowy ma "<<punktyPublikacyjne<<" punktów i kategorie: "<<kategoria();
}

int PracNaukowy::getPunktyPublikacyjne() const {
    return punktyPublikacyjne;
}

void PracNaukowy::setPunktyPublikacyjne(int punktyPublikacyjne) {
    PracNaukowy::punktyPublikacyjne = punktyPublikacyjne;
}
