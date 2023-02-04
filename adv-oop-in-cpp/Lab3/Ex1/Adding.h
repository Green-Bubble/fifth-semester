//
// Created by marcinskic on 11/3/22.
//

#ifndef EX1_ADDING_H
#define EX1_ADDING_H

#include <iostream>
using namespace std;
//W pliku header są zawarte definicje a nie tylko deklaracje, wynika to z przyjętej praktyki dla szablonów

template <typename T>   //Szablon klasy przechowującej dowolny element który obsługuje operator '+'
class Adding                //W przeciwnym wypadku metoda add nie będzie działać poprawnie
{
private:
    T element;
public:
    Adding(T value);
    void add(T value);
    void show();
};
template <typename T>
Adding<T>::Adding(T value)
{
    element=value;
}
template <typename T>
void Adding<T>::add(T value)
{
    element=element+value;
}
template <typename T>
void Adding<T>::show()
{
    cout<<"Element: "<<element<<endl;
}
#endif //EX1_ADDING_H
