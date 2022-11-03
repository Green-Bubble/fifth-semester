#include <iostream>
#include <limits>
#include "Adding.h"
#include "Student.h"

template <typename T>
void showAll(T* tab[], int n)
{
    for(int i=0;i<n;i++)
    tab[i]->show();
}

template <typename T>
void checkType(T a) {
    T val = numeric_limits<T>::max();
    cout << val << endl;
}

int main() {
    Adding<int>* arrAdd[3];
    for(int i=0;i<3;i++)
        {
        arrAdd[i]=new Adding<int>(i);
        }
    showAll(arrAdd,3);
    Student<string>* arrStu[2];
    for(int i=0;i<3;i++){
        arrStu[i]=new Student<string>(i+2,"Ala");
        }
    showAll(arrStu,3);
    for(int i=0; i<3; i++)
        delete arrAdd[i];
    for(int i=0; i<2; i++)
        delete arrStu[i];

    checkType<int> (1);
}
