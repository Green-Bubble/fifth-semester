//
// Created by marci on 10.12.2022.
//


#include "BufferFile.h"

BufferFile::BufferFile(std::string filePath) {
    std::cout<<"Konstruktor BufferFile"<<std::endl;
    this->filePath = filePath;
}

BufferFile::~BufferFile() {
    std::cout<<"Destruktor BufferFile"<<std::endl;
}

void BufferFile::add(int a) {
    filePtr = std::unique_ptr<std::fstream>(new std::fstream(filePath,std::ios::app));

    *filePtr << std::to_string(a)<<std::endl;
    filePtr->close();
    filePtr.reset();
}

void BufferFile::write() {
    filePtr = std::unique_ptr<std::fstream>(new std::fstream(filePath));

    std::string line;
    while(std::getline(*filePtr,line)){
        std::cout<<line<<" ";
    }
    std::cout<<std::endl;
    filePtr->close();
    filePtr.reset();
}
