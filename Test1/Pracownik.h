//
// Created by marcinskic on 12/15/22.
//

#ifndef TEST1_PRACOWNIK_H
#define TEST1_PRACOWNIK_H

#include <string>

struct simpleDate{
    int year;
    int month;
};

class Pracownik {
private:
    std::string imie;
    std::string nazwisko;
    std::string tytul;
    simpleDate data_zatrudnienia;
    std::string stanowisko;
    float pensjaZasadnicza;

public:
    Pracownik();
    Pracownik(std::string imie,std::string nazwisko,std::string tytul,simpleDate data_zatrudnienia,std::string stanowisko,float pensjaZasadnicza);
    virtual ~Pracownik();
    virtual float wyplata() = 0;
    virtual void wyswietl();
    int stazPracy();

    const std::string &getImie() const;

    void setImie(const std::string &imie);

    const std::string &getNazwisko() const;

    void setNazwisko(const std::string &nazwisko);

    const std::string &getTytul() const;

    void setTytul(const std::string &tytul);

    const simpleDate &getDataZatrudnienia() const;

    void setDataZatrudnienia(const simpleDate &dataZatrudnienia);

    const std::string &getStanowisko() const;

    void setStanowisko(const std::string &stanowisko);

    float getPensjaZasadnicza() const;

    void setPensjaZasadnicza(float pensjaZasadnicza);
};


#endif //TEST1_PRACOWNIK_H
