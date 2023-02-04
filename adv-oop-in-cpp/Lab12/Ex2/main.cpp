#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "Car.h"

using namespace std;

void showVec(vector<tuple<int,Car>> cars) {
    for_each(cars.begin(),cars.end(),[](auto car){
       cout<<get<0>(car)<<". ";
       get<1>(car).show();
    });
}

int main() {
    vector<tuple<int,Car>> cars;
    int index = 1;

    cars.push_back(make_tuple(index,Car("BMW",1999,8)));
    index++;
    cars.push_back(make_tuple(index,Car("Audi",2005,10)));
    index++;
    cars.push_back(make_tuple(index,Car("Volvo",1990,6)));
    index++;
    cars.push_back(make_tuple(index,Car("Bugatti",2015,9)));
    index++;
    cars.push_back(make_tuple(index,Car("Polonez",1959,4)));
    index++;
    showVec(cars);
    cout<<endl;

    //Sortowanie rosnąco względem produkcji
    sort(cars.begin(),cars.end(),[](tuple<int,Car> t1,tuple<int,Car> t2){
        return get<1>(t1).getProdYear() < get<1>(t2).getProdYear();
    });
    showVec(cars);
    cout<<endl;

    //Sortowanie malejąco względem pojemności silnika
    sort(cars.begin(),cars.end(),[](tuple<int,Car> t1,tuple<int,Car> t2){
        return get<1>(t1).getEngineCapacity() > get<1>(t2).getEngineCapacity();
    });
    showVec(cars);

    return 0;
}
