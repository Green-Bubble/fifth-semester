//
// Created by marci on 31.10.2022.
//

#include "Buffer.h"
#include <iostream>

Buffer::Buffer() {
    size = 10;
    array = new int[size];
    index = 0;
}

Buffer::Buffer(int size) {
    this->size = size;
    array = new int[size];
    index = 0;
}

Buffer::~Buffer() {
    delete array;
}

void Buffer::add(int value) {
    array[index] = value;
    index++;
}

int Buffer::getSize() {
    return size;
}

int Buffer::getArray(int i) {
    return array[i];
}

int Buffer::getFirst() {
    return index;
}

void Buffer::setFirst(int value) {
    array[index] = value;
    index++;
}

void Buffer::setArray(int pos, int value) {
    array[pos] = value;
}

void Buffer::show() {
    std::cout<<"Array: ";
    for(int i = 0; i < index; i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}
