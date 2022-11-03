#include <iostream>

using namespace std;

template <typename T>
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
    int arrInt[5] = {1,2,351,2,5};
    float arrFloat[4] = {0.2,0.5,512,12};

    findMin(arrInt,5);
    findMin(arrFloat,4);
    return 0;
}
