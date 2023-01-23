//
//  main.swift
//  Ex5
//
//  Created by student on 19/12/2022.
//

import Foundation

var p1 = Person(name:"Marek",surname:"Kowalski",birthYear:1995)
var p2 = Person(name: "Marcin", surname: "Skic", birthYear: 1995)

if(p1.calculateAge() > p2.calculateAge()){
    print("Osoba")
    p1.show()
    print(" jest starsza, a")
    p2.show()
    print(" jest mlodsza")
} else if(p1.calculateAge()<p2.calculateAge()){
    print("Osoba")
    p2.show()
    print(" jest starsza, a")
    p1.show()
    print(" jest mlodsza")
} else {
    print("Osoby")
    p1.show()
    print(" i ")
    p2.show()
    print(" są tego samego wieku")
}

var e1 = Employee(name:"Krzysztof",surname:"Wójcik",birthYear:1980,employmentYear:2000,position: Position.Manager,hourlyRate: 15,workedHours: 40,companyName:"CocaCola")

e1.show()

