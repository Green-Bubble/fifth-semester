//
// Created by marcinskic on 12/15/22.
//

#include "Pracownik.h"
#include <iostream>

Pracownik::Pracownik() {

}

Pracownik::Pracownik(std::string imie, std::string nazwisko, std::string tytul, simpleDate data_zatrudnienia,
                     std::string stanowisko, float pensjaZasadnicza) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->tytul = tytul;
    this->data_zatrudnienia = data_zatrudnienia;
    this->stanowisko = stanowisko;
    this->pensjaZasadnicza = pensjaZasadnicza;
}

Pracownik::~Pracownik() {

}

void Pracownik::wyswietl() {
    std::cout<<imie<<" "<<nazwisko<<" o tytule "<<tytul<<" pracuje od "<<data_zatrudnienia.year<<"."<<data_zatrudnienia.month<<" na stanowisku: "<<stanowisko<<" zarabiając zasadniczo: "<<pensjaZasadnicza<<" z wyplata: "<<wyplata();
}

int Pracownik::stazPracy() {
    simpleDate aktualnaData;
    aktualnaData.year = 2022;
    aktualnaData.month = 12;

    if(aktualnaData.month - data_zatrudnienia.month >= 0){
        return aktualnaData.year - data_zatrudnienia.year;
    } else {
        return aktualnaData.year - data_zatrudnienia.year-1;
    }
}

const std::string &Pracownik::getImie() const {
    return imie;
}

void Pracownik::setImie(const std::string &imie) {
    Pracownik::imie = imie;
}

const std::string &Pracownik::getNazwisko() const {
    return nazwisko;
}

void Pracownik::setNazwisko(const std::string &nazwisko) {
    Pracownik::nazwisko = nazwisko;
}

const std::string &Pracownik::getTytul() const {
    return tytul;
}

void Pracownik::setTytul(const std::string &tytul) {
    Pracownik::tytul = tytul;
}

const simpleDate &Pracownik::getDataZatrudnienia() const {
    return data_zatrudnienia;
}

void Pracownik::setDataZatrudnienia(const simpleDate &dataZatrudnienia) {
    data_zatrudnienia = dataZatrudnienia;
}

const std::string &Pracownik::getStanowisko() const {
    return stanowisko;
}

void Pracownik::setStanowisko(const std::string &stanowisko) {
    Pracownik::stanowisko = stanowisko;
}

float Pracownik::getPensjaZasadnicza() const {
    return pensjaZasadnicza;
}

void Pracownik::setPensjaZasadnicza(float pensjaZasadnicza) {
    Pracownik::pensjaZasadnicza = pensjaZasadnicza;
}