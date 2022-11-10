//
// Created by marcinskic on 11/10/22.
//

#ifndef EX1_EVEN_H
#define EX1_EVEN_H

class Even
{
private:
    int divider;
public:
    Even(int divider);
    bool operator( )(int x);
};


#endif //EX1_EVEN_H
