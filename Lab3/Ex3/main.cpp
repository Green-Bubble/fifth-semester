#include <iostream>

#include "Array.h"

int main() {
    Array<int> array1;

    array1.add(4);
    array1.add(2);
    array1.add(5);
    array1.add(1);

    array1.sort();
    array1.show();

    cout<<"Max: "<<array1.getMax()<<endl;
    cout<<"Na indeks 2: "<<array1.getElement(2)<<endl;

    Array<string> array2(4);

    array2.add("bist");
    array2.add("verheiratet");
    array2.add("nicht");
    array2.add("Du");

    array2.show();
    array2.sort();
    array2.show();

    cout<<"Max: "<<array2.getMax()<<endl;
    cout<<"Na indeks 1: "<<array2.getElement(1)<<endl;
    return 0;
}
