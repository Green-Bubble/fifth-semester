//
// Created by marci on 10.12.2022.
//

#ifndef EX1_BUFFERARR_H
#define EX1_BUFFERARR_H


#include <memory>
#include "Buffer.h"

class BufferArr: public Buffer {
private:
    std::unique_ptr <int[]> arr;
    std::unique_ptr<int> maxSize;
    std::unique_ptr<int> currentIndex;
public:
   BufferArr(int arrSize);
   ~BufferArr();
   void add(int a) override;
   void write() override;
};


#endif //EX1_BUFFERARR_H
