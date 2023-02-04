//
// Created by marcinskic on 12/15/22.
//

#include "PracDydaktyczny.h"
#include <iostream>

PracDydaktyczny::PracDydaktyczny(const std::string &imie, const std::string &nazwisko, const std::string &tytul,
                                 const simpleDate &dataZatrudnienia, const std::string &stanowisko,
                                 float pensjaZasadnicza, int pensum, int godzinyRealizowane) : Pracownik(imie, nazwisko,
                                                                                                         tytul,
                                                                                                         dataZatrudnienia,
                                                                                                         stanowisko,
                                                                                                         pensjaZasadnicza),
                                                                                               pensum(pensum),
                                                                                               godzinyRealizowane(
                                                                                                       godzinyRealizowane) {
    this->godzinyRealizowane = godzinyRealizowane;
    this->pensum = pensum;
}

int PracDydaktyczny::getPensum() const {
    return pensum;
}

void PracDydaktyczny::setPensum(int pensum) {
    PracDydaktyczny::pensum = pensum;
}

int PracDydaktyczny::getGodzinyRealizowane() const {
    return godzinyRealizowane;
}

void PracDydaktyczny::setGodzinyRealizowane(int godzinyRealizowane) {
    PracDydaktyczny::godzinyRealizowane = godzinyRealizowane;
}

int PracDydaktyczny::procentNadliczbowe() {
    return ((godzinyRealizowane-pensum)/pensum)*100;
}

PracDydaktyczny::PracDydaktyczny() {

}

PracDydaktyczny::~PracDydaktyczny() {

}

float PracDydaktyczny::wyplata() {
    float result = getPensjaZasadnicza();

    if(stazPracy() > 5){
        result += ((getPensjaZasadnicza()*3)/100)*(stazPracy()-5);
    }

    result += getPensjaZasadnicza() * procentNadliczbowe()/100;

    return result;
}

void PracDydaktyczny::wyswietl() {
    Pracownik::wyswietl();
    std::cout<<std::endl;
    std::cout<<"Jako pracownik dydaktyczny ma pensum "<<pensum<<" a realizowane godziny: "<<godzinyRealizowane<<" co daje "<<procentNadliczbowe()<<"% nadgodzin";
}

