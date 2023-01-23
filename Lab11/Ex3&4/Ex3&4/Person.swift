//
//  Person.swift
//  Ex5
//
//  Created by student on 19/12/2022.
//

import Foundation

class Person {
    var name:String
    var surname:String
    var birthYear:Int
    
    init(name: String, surname: String, birthYear: Int) {
        self.name = name
        self.surname = surname
        self.birthYear = birthYear
    }
    
    func calculateAge() -> Int{
        return 2022-birthYear
    }
    
    func show(){
        print(name,surname,birthYear,terminator: "")
    }
}
