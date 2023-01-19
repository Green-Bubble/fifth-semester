#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Car.h"
#include "ExG3B.h"

using namespace std;

template <typename T>
void showCollection(T col){
    int index = 1;
    for_each(col.begin(),col.end(),[&index](auto el){
        cout<<index<<". ";
       el.show();
       index++;
    });
}

int main() {
    vector<Car> cars;
    cout<<"Domyslna kolejność: "<<endl;//------------------------------------------------------------
    cars.push_back(Car("BMW",1999,6));
    cars.push_back(Car("Toyota",2005,5));
    cars.push_back(Car("Koenigsegg",2015,9));
    cars.push_back(Car("Star",1970,4));
    //cars.push_back(Car("Ufo",2434,-5));

    showCollection(cars);

    cout<<endl<<endl<<"Posortowane rosnaco wzgledem roku produkcji: "<<endl;//--------------------------
    sort(cars.begin(),cars.end(),[](Car a, Car b){
       return a.getProdYear() < b.getProdYear();
    });

    showCollection(cars);

    cout<<endl<<endl<<"Posortowane malejaco wzgledem pojemnosci silnika: "<<endl;//--------------------------
    sort(cars.begin(),cars.end(),[](Car a, Car b){
        return a.getEngineCap() > b.getEngineCap();
    });

    showCollection(cars);

    cout<<endl<<endl;//----------------------------------------------------------------------------------------
    int licznik = 1, engineCapThreshold = 4;
    auto calculateEngineCap = [cars,licznik,engineCapThreshold](){
        auto result = accumulate(cars.begin(),cars.end(),0,[licznik,engineCapThreshold](int init, Car c){
            if(c.getEngineCap() < 0) throw -1;
            return c.getEngineCap() > engineCapThreshold ? init +1 : init;
        });

        cout<<"Samochody o pojemnosci silnika wiekszej od "<<engineCapThreshold<<": "<<result<<endl;//--------------------------
    };

    try{
        calculateEngineCap();
    } catch(int) {
        cout<<"Trafiono na samochod o ujemnej pojemnosci silnika!"<<endl;
    }

    //------------------ZADANIE B--------------------------------------------------------
    ExG3B::saveToFile();

    return 0;
}
