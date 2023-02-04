//
// Created by marcinskic on 11/3/22.
//

#ifndef EX3_ARRAY_H
#define EX3_ARRAY_H

#include <string>
#include <iostream>

using namespace std;

template <typename T>   //Szablon klasy przechowującej tablicę elementów i wykonującej operacje na niej
class Array {
private:
    T* array;
    int size;
    int index = 0;
public:
    Array(int size){
        this->size = size;
        array = new T[size];
    }
    Array() {
        size = 10;
        array = new T[10];
    }
    virtual ~Array() {
        delete array;   //Usunięcie tablicy prostych elementów (int, float, etc.)
    }
    void sort() {   //Sortowanie bąbelkowe tablicy
        for(int i = 0; i < index-1; i++){
            for(int x = 0; x < index-i-1; x++){
                if(array[x] > array[x+1]){
                    swap(array[x],array[x+1]);
                }
            }
        }
    }

    T getMax() {
        T max = array[0];
        for(int i = 1; i < index; i++){
            if(max < array[i]){
                max = array[i];
            }
        }
        return max;
    }

    void show() {
        cout<<"Array: ";
        for(int i = 0; i < index; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    void add(T element) {
        array[index] = element;
        index++;
    };

    T getElement(int index){
        return array[index];
    }
};

//Specjalizacja wybranych metod dla typu string
template<>
void Array<string>::sort() {
    for(int i = 0; i < index-1; i++){
        for(int x = 0; x < index-i-1; x++){
            if(array[x].length() > array[x+1].length()){
                array[x].swap(array[x+1]);
            }
        }
    }
}

template<>
string Array<string>::getMax() {
    string max = array[0];
    for(int i = 1; i < index; i++){
        if(max.length() < array[i].length()){

            max = array[i];
        }
    }
    return max;
}

template<>
Array<string>::~Array() {
    delete []array; //Usunięcie tablicy obiektów
}

/*template<>
class Array<string>{
private:
    string* array;
    int size;
    int index = 0;
public:
    Array(int size){
        index = 0;
        this->size = size;
        array = new string [size];
    }
    Array() {
        index = 0;
        size = 10;
        array = new string [10];
    }
    virtual ~Array() {
        delete []array; //Usunięcie tablicy obiektów
    }

    void sort() {
        for(int i = 0; i < index-1; i++){
            for(int x = 0; x < index-i-1; x++){
                if(array[x].length() > array[x+1].length()){
                    array[x].swap(array[x+1]);
                }
            }
        }
    }
    string getMax() {
        string max = array[0];
        for(int i = 1; i < index; i++){
            if(max.length() < array[i].length()){

                max = array[i];
            }
        }
        return max;
    }

    void show() {
        cout<<"Array: ";
        for(int i = 0; i < index; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    void add(string element) {
        array[index] = element;
        index++;
    };

    string getElement(int index){
        return array[index];
    }
};
*/
#endif //EX3_ARRAY_H
