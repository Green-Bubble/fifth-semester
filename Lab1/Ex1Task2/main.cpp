#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int howManyProtectedAnimals(Animal **animals,int length){
    int protectedAmount = 0;
    for(int i = 0; i < length;i++){
        if(animals[i]->getIsProtected()){
            protectedAmount++;
        }
    }
    return protectedAmount;
}

void howManyTrackerDogs(Dog **dogs,int length){
    for(int i = 0; i < length; i++){
        if(dogs[i]->getSkillLevel(Dog::trackerSkills) > dogs[i]->getSkillLevel(Dog::guideSkills)){
            dogs[i]->info();
        }
    }
}

void howManyCats(Cat *cats,int length){
    for(int i = 0; i < length; i++){
        Cat cat = cats[i];
        int mice = 0;

        cat.info();

        for(int x = 0; x < 5; x++){
            mice += cat.getMice(x);
        }
        cout<<"Upolowal lacznie: "<<mice<<" myszy"<<endl;
    }
}

int main() {
    //Stworzenie dynamicznych obiektów
    Animal *anim1 = new Animal("Strus",2);
    Animal *anim2 = new Animal("Lew",4);
    Animal *anim3 = new Animal("Kura",2,false);
    Animal *anim4 = new Animal("Slon",5,true);
    Animal *anim5 = new Animal("Osa",6,false);

    Dog *dog = new Dog("Lucio");
    Dog *dog2 = new Dog("Albercik","Husky",2,5);
    Dog *dog3 = new Dog("Barbara","Chihuahua",1,0);

    //Stworzenie statycznych tablic upolowanych myszy
    int huntedMice[5] = {5,3,231,4,5};
    int huntedMice2[5] = {1,2,3,4,5};

    //Stworzenie statycznych obiektow i skorzystanie z setterow rodzica i init do przypisania wartosci
    Cat cat;
    Cat cat2;

    cat.setName("Kasia");
    cat.setLimbNr(4);
    cat.setIsProtected(false);
    cat.initCat(5,huntedMice);

    cat2.setName("Kater");
    cat2.setLimbNr(3); //Mial wypadek :<
    cat2.setIsProtected(false);
    cat2.initCat(1,huntedMice2);

    //Stworzenie tablic i sprawdzenie metod
    Animal *aminals[6] = {anim1,anim2,anim3,anim4,anim5,dog};   //Statyczna tablica dynamicznych obiektow
    cout<<"Chronionych zwierzat jest: "<<howManyProtectedAnimals(aminals,6)<<endl;

    Dog **dogs = new Dog*[3]{dog,dog2,dog3};    //Dynamiczna tablica dynamicznych obiektow
    cout<<endl<<"Psy tropiciele: "<<endl;
    howManyTrackerDogs(dogs,3);

    Cat cats[2] = {cat,cat2};   //Statyczna tablica statycznych obiektow
    cout<<"Koty:"<<endl;
    howManyCats(cats,2);

    return 0;
}
