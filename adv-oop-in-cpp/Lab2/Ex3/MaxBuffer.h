//
// Created by marci on 31.10.2022.
//

#ifndef EX3_MAXBUFFER_H
#define EX3_MAXBUFFER_H


#include "Buffer.h"

class MaxBuffer : public Buffer {
public:
    MaxBuffer(int size);
    double calculate() override;
    void add(int value);
};


#endif //EX3_MAXBUFFER_H
