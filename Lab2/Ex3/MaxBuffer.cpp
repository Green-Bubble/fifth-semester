//
// Created by marci on 31.10.2022.
//

#include "MaxBuffer.h"

#include <iostream>

using namespace std;

double MaxBuffer::calculate() {
    int currentMax = getArray(0);
    for (int i = 1 ; i < getSize(); i++){
        if(currentMax < getArray(i)) currentMax = getArray(i);
    }
    return currentMax;
}

MaxBuffer::MaxBuffer(int size) : Buffer(size) {

}

void MaxBuffer::add(int value) {
    if(getFirst() == getSize()){
        cout<<"Full array"<<endl;
        return;
    }
    Buffer::add(value);
}


