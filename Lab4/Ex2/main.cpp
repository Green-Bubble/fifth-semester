#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void showElement(T &elem){
    cout<<elem<<" ";
}

int main() {
    srand(time(nullptr));

    int listSize = (rand() % 500 + 1);
    list<int> list;

    for(auto i = 0; i < listSize; i++) {
        int elem = (rand() % 201 - 100);
        if(elem < 0){
            list.push_back(elem);
        } else {
            list.push_front(elem);
        }
    }
    cout<<"------------------STWORZONA LISTA------------------------"<<endl;
    for_each(list.begin(),list.end(), showElement<int>);
    return 0;
}
