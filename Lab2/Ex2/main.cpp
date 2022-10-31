#include <iostream>
#include "Developer.h"
#include "Employee.h"
#include "TeamLeader.h"

void whoWorkMoreThan5Years(Employee** employees, int length){
    cout<<"Pracownicy pracujący ponad 5 lat: "<<endl;
    for(int i = 0; i < length; i++){
        if(employees[i]->getExperience() > 5){
            employees[i]->show();
        }
    }
}

int howManyEarnLessThanMeanBonus(Employee** employees, int length){
    float bonusSum = 0;
    for(int i = 0 ; i < length ; i++){
        bonusSum +=employees[i]->calculateBonus(100);
    }
    bonusSum /= length;

    int employeesBelowAverage = 0;
    cout<<"Pracownicy którzy maja bonus nizszy od sredniej: "<<endl;
    for(int i = 0; i < length; i++){
        if(employees[i]->calculateBonus(100) < bonusSum){
            employees[i]->show();
            employeesBelowAverage++;
        }
    }

    return employeesBelowAverage;

}

int main() {
    Developer developer("Stefanski",30,5,2010);
    Employee* employee = &developer;
    Developer* developer2 = new Developer("Krzysztowski",40,7,2010);
    TeamLeader* teamLeader = new TeamLeader("Kowalski",35,5,510);
    TeamLeader* teamLeader2 = new TeamLeader("Kacperczyk",40,7,2010);

    Employee** employees = new Employee* [4]{employee,developer2,teamLeader,teamLeader2};

    whoWorkMoreThan5Years(employees,4);
    int amount = howManyEarnLessThanMeanBonus(employees,4);
    cout<<"I jest ich lacznie: "<<amount<<endl;
}
