//
// Created by marcinskic on 11/3/22.
//

#ifndef EX1_ADDING_H
#define EX1_ADDING_H

#include <iostream>
using namespace std;

template <typename T>
class Adding
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
