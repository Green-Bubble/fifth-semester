//
// Created by marci on 10.12.2022.
//

#ifndef EX1_BUFFER_H
#define EX1_BUFFER_H


class Buffer {
public:
    virtual void add(int a) = 0;
    virtual void write() = 0;
    Buffer();
    virtual ~Buffer();
};


#endif //EX1_BUFFER_H
