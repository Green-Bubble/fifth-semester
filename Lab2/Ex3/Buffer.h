//
// Created by marci on 31.10.2022.
//

#ifndef EX3_BUFFER_H
#define EX3_BUFFER_H


class Buffer {
private:
    int* array;
    int size;
    int index;
public:
    Buffer();
    Buffer(int size);
    virtual ~Buffer();
    void add(int value);
    double virtual calculate() = 0;
    int getSize();
    int getArray(int i);
    int getFirst();
    void setFirst(int value);
    void setArray(int pos, int value);
    void show();
};


#endif //EX3_BUFFER_H
