#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;
int main() {
    cout<<"Test osoby: "<<endl;
    Person person("Pawel","Jakis",10);
    person.showInfoPerson();
    cout<<"Czy jest pelnoletnia?: "<<person.is_18()<<endl;

    cout<<endl<<endl<<"Test nauczycieli: "<<endl;
    Teacher teacher("Kuba","Cos",10,5,"Phd");

    teacher.showInfoTeacher();
    cout<<"Czy Kuba ma Phd?: "<<teacher.is_Phd()<<endl;

    cout<<endl<<endl<<"Test studenta: "<<endl;
    cout<<"Statyczne tablica, statyczne obiekty: "<<endl;
    Student students1[2];
    for(int i =0; i<2;i++){
        students1[i].init("Anna", "Nowak", 20 + i);
        students1[i].setIndex(to_string(94333 + i));

        students1[i].showInfoStudent();
    }

    cout<<endl<<"Dynamiczna tablica, statyczne obiekty: "<<endl;
    Student* students2 = new Student [2];
    for(int i = 0; i<2;i++){
        students2[i].init("Anna", "Nowak", 20+1);
        students2[i].setIndex(to_string(96542 + i));

        students2[i].showInfoStudent();
    }

    cout<<endl<<"Statyczna tablica, dynamiczne obiekty: "<<endl;
    Student* students3[2];
    for(int i = 0; i<2;i++){
        students3[i] = new Student("Anna", "Nowak", 20+1);
        students3[i]->setIndex(to_string(96542 + i));

        students3[i]->showInfoStudent();
    }

    cout<<endl<<"Dynamiczna tablica, dynamiczne obiekty: "<<endl;
    Student** students4 = new Student* [2];
    for(int i = 0; i<2;i++){
        students4[i] = new Student("Anna", "Nowak", 20+1);
        students4[i]->setIndex(to_string(98742 + i));

        students4[i]->showInfoStudent();
    }


    return 0;
}
