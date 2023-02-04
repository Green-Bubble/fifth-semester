//
// Created by marci on 31.10.2022.
//

#ifndef EX3_MEANBUFFER_H
#define EX3_MEANBUFFER_H


#include "Buffer.h"

class MeanBuffer : public Buffer{
public:
    MeanBuffer(int size);
    double calculate() override;
};


#endif //EX3_MEANBUFFER_H
