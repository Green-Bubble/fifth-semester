#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "BufferArr.h"
#include "BufferFile.h"

int main() {
    srand(time(NULL));

    std::vector<Buffer*> buffers;

    buffers.push_back(new BufferArr(5));
    buffers.push_back(new BufferArr(8));
    buffers.push_back(new BufferArr(2));
    buffers.push_back(new BufferFile("numbers.txt"));
    buffers.push_back(new BufferFile("numbers2.txt"));
    buffers.push_back(new BufferFile("numbers3.txt"));

    std::for_each(buffers.begin(),buffers.end(),[](Buffer* b){
        int randSize = rand()%10+1;
        for(int i = 0; i < randSize; i++){
            b->add(rand()%1000);
        }
    });

    std::for_each(buffers.begin(),buffers.end(),[](Buffer* b){
        b->write();
    });

    std::for_each(buffers.begin(),buffers.end(),[](Buffer* b){
        delete b;
    });
}
