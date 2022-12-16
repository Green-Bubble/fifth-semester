//
// Created by marcinskic on 12/15/22.
//

#ifndef TEST1_PRACDYDAKTYCZNY_H
#define TEST1_PRACDYDAKTYCZNY_H


#include "Pracownik.h"

class PracDydaktyczny : public Pracownik{
private:
    int pensum;
    int godzinyRealizowane;
public:
    int procentNadliczbowe();
    PracDydaktyczny();
    PracDydaktyczny(const std::string &imie, const std::string &nazwisko, const std::string &tytul,
                    const simpleDate &dataZatrudnienia, const std::string &stanowisko, float pensjaZasadnicza,
                    int pensum, int godzinyRealizowane);
    virtual ~PracDydaktyczny();

    virtual float wyplata() override;

    virtual void wyswietl() override;

    int getPensum() const;

    void setPensum(int pensum);

    int getGodzinyRealizowane() const;

    void setGodzinyRealizowane(int godzinyRealizowane);
};


#endif //TEST1_PRACDYDAKTYCZNY_H
