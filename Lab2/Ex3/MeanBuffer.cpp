//
// Created by marci on 31.10.2022.
//

#include "MeanBuffer.h"

double MeanBuffer::calculate() {
    double mean = 0;
    for(int i = 0; i < getSize(); i++){
        mean += int(getArray(i));
    }
    mean /= getSize();
    return mean;
}

MeanBuffer::MeanBuffer(int size) : Buffer(size) {

}
