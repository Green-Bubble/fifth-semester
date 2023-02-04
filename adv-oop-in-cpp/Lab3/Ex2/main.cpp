#include <iostream>

using namespace std;

template <typename T>   //Funkcja szablonowa, szukająca elementu maksymalnego w tablicy
void findMin(T* arr, int size){
    T min = arr[0];
    for(auto i = 1; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    cout<<"Najmniejszy element to: "<<min<<endl;
}

int main() {
    int arrInt[5] = {54,2,351,1,5};
    float arrFloat[4] = {0.2,0.5,512,12};

    findMin(arrInt,5);  //Działa zarówno na int
    findMin(arrFloat,4);    //Jak i na float
    return 0;
}
