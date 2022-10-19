#include <iostream>
#include "Animal.h"
#include "Dog.h"

int main() {

    Dog *dog = new Dog("Lucio");

    dog->info();

    return 0;
}
