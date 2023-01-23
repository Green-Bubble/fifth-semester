//
//  Employee.swift
//  Ex5
//
//  Created by student on 19/12/2022.
//

import Foundation

enum Position : CustomStringConvertible{
    case Worker
    case Manager
    case CEO
    
    var description: String{
        switch self {
        case .Worker: return "Worker"
        case .Manager: return "Manager"
        case .CEO: return "CEO"
        }
    }
}

class Employee : Person {
    
    var employmentYear:Int
    var position:Position
    var hourlyRate:Float
    var workedHours:Int
    var companyName:String
    
    init(name:String, surname:String, birthYear:Int, employmentYear: Int, position: Position, hourlyRate: Float, workedHours: Int, companyName: String) {
        self.employmentYear = employmentYear
        self.position = position
        self.hourlyRate = hourlyRate
        self.workedHours = workedHours
        self.companyName = companyName
        
        super.init(name: name, surname: surname, birthYear: birthYear)
    }
    
    func getYearsEmployed() -> Int{
        return 2022 - employmentYear
    }
    
    func getSalary() -> Float{
        return Float(workedHours) * hourlyRate
    }
    
    override func show() {
        super.show()
        print("\nZatrudniona w \(companyName) od \(employmentYear) na stanowisku \(position) z zarobkami: \(workedHours)h * \(hourlyRate)$ = \(getSalary())$")
    }
}
