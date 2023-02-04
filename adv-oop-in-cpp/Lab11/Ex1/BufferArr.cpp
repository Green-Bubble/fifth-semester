//
// Created by marci on 10.12.2022.
//

#include <iostream>
#include "BufferArr.h"

BufferArr::BufferArr(int arrSize) {
    std::cout<<"Konstruktor BufferArr"<<std::endl;
    arr = std::unique_ptr<int[]> (new int[arrSize]);
    maxSize = std::unique_ptr<int>(new int);
    currentIndex = std::unique_ptr<int>(new int);

    *maxSize = arrSize;
    *currentIndex = 0;
}

BufferArr::~BufferArr() {
    std::cout<<"Destruktor BufferArr"<<std::endl;
    maxSize.reset();
    currentIndex.reset();
    arr.reset();
}


void BufferArr::add(int a) {
    if(*currentIndex == *maxSize){
        std::cout<<"Tablica pelna, nie dodano elementu"<<std::endl;
        return;
    }

    arr[*currentIndex] = a;
    (*currentIndex)++;
}

void BufferArr::write() {
    for(int i =0; i < *currentIndex; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
