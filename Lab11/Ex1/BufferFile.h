//
// Created by marci on 10.12.2022.
//

#ifndef EX1_BUFFERFILE_H
#define EX1_BUFFERFILE_H

#include <fstream>
#include <iostream>
#include <memory>
#include "Buffer.h"

class BufferFile : public Buffer {
private:
    std::string filePath;
    std::unique_ptr<std::fstream> filePtr;
public:
    BufferFile(std::string filePath);
    ~BufferFile();
    void add(int a) override;
    void write() override;
};


#endif //EX1_BUFFERFILE_H
