//
// Created by marcinskic on 12/15/22.
//

#ifndef TEST1_PRACNAUKOWY_H
#define TEST1_PRACNAUKOWY_H


#include "Pracownik.h"
#include <string>

class PracNaukowy : public Pracownik{
private:
    int punktyPublikacyjne;
public:
    std::string kategoria();

    PracNaukowy(const std::string &imie, const std::string &nazwisko, const std::string &tytul,
                const simpleDate &dataZatrudnienia, const std::string &stanowisko, float pensjaZasadnicza,
                int punktyPublikacyjne);
    PracNaukowy();

    int getPunktyPublikacyjne() const;

    void setPunktyPublikacyjne(int punktyPublikacyjne);

    ~PracNaukowy() override;

    float wyplata() override;

    void wyswietl() override;
};


#endif //TEST1_PRACNAUKOWY_H
