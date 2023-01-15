#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <numeric>

using namespace std;

template <typename T>
void showVector(vector<T> vec){
    std::for_each(vec.begin(), vec.end(),[](auto number){
        cout<<number<<"|";
    });
    cout<<"\r"<<endl;
}

int main() {
    srand(time(NULL));
    vector<int> numbers;

    //Wypełnianie
    for(int i = 0; i < rand()%50 + 50; i++){
        numbers.push_back(rand()%100 - 49);
    }

    //Wyświetlanie------------------------------------------------
    showVector(numbers);

    //Średnia arytmetyczna
    cout<<"Srednia arytmetyczna:"<<((float)accumulate(numbers.begin(),numbers.end(),0)/(float)numbers.size())<<endl;

    //Policzenie parzystych---------------------------------------
    cout<<"Liczba parzystych elementow: "<<(accumulate(numbers.begin(),numbers.end(),0,[](auto init,auto number){
        return number%2 == 0 ? init+1 : init;
    }))<<endl;

    //Usuwanie ujemnych i wyświetlanie efektu---------------------
    auto eraseBegin = remove_if(numbers.begin(),numbers.end(),[](auto number){
        return number < 0;
    });
    numbers.erase(eraseBegin,numbers.end());

    cout<<"Po usunieciu: "<<endl;
    showVector(numbers);

    //Sortowanie parzyste / nieparzyste---------------------------
    sort(numbers.begin(),numbers.end(),[](auto a,auto b){
       return a % 2 == 0 && b % 2 == 1;
    });

    cout<<"Po sortowaniu: "<<endl;
    showVector(numbers);

    //Nadpisanie liczbą przeciwną----------------------------------
    transform(numbers.begin(),numbers.end(),numbers.begin(),[](auto number){
        return -number;
    });
    cout<<"Po nadpisaniu: "<<endl;
    showVector(numbers);

    //Ile mniejszych od---------------------------------------------
    int argument = -45;

    cout<<"Liczba elementow mniejszych niz "<<argument<<": "<<(accumulate(numbers.begin(),numbers.end(),0,[argument](auto init,auto number){
        return number < argument ? init+1 : init;
    }))<<endl;

    return 0;
}
