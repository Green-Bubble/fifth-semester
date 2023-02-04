//
//  main.swift
//  Ex4
//
//  Created by student on 05/12/2022.
//

import Foundation

var exampleSurnames = ["Nowak","Kowalski","Wiśniewski","Wójcik","Kowalczyk","Kamiński"]

var students: [String:String] = [:]

exampleSurnames.shuffle()

for i in 0..<5 {
    students[String(Int.random(in: 90000...95000))] = exampleSurnames[i]
}

print(students)

while(true){
    print("Podaj identyfikator studenta: ",terminator: "")
    let id = readLine()!

    guard let foundSurname = students[id] else {
        print("Nie istnieje student o takim id")
        continue
    }
    
    print("Podaj nazwisko studenta: ",terminator: "")
    let surname = readLine()!
    
    if(foundSurname != surname){
        print("Istnieje student o takim id ale ma inne nazwisko")
        continue
    }
    
    print(id,surname)
    
    print("Czy chcesz usunąć tego studenta? (y/n): ",terminator: "")
    let choice = readLine()!
    
    if(choice == "y" || choice == "Y"){
        students.removeValue(forKey: id)
    }
    
    break
}

print("Po operacji: ")
print(students)
