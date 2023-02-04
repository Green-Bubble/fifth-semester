//
//  main.swift
//  Ex4
//
//  Created by student on 16/01/2023.
//

import Foundation

enum ATC_Errors : Error {
    case InsufficientFunds
    case LowMoneyInATC
    case SurpassedDailyLimit
    case NoMatchingNotes
    case ImproperValue
}

var nominals = [200,200,200,200,100,100,100,100,100,50,50,50,20,20,20,10,10,5,1,1,1,1]
var funds = 3000
var dailyLimit = 2000

func withdrawMoney() throws {
    print("Ile chcesz wypłacić: ")
    guard let money = Int(readLine()!) else {
        throw ATC_Errors.ImproperValue
    }
    
    guard funds > money else {
        throw ATC_Errors.InsufficientFunds
    }
    guard dailyLimit > money else {
        throw ATC_Errors.SurpassedDailyLimit
    }
    
    var leftNominals = nominals
    var waitingMoney = money
    
    var index = 0
    for nominal in nominals {
        if(nominal <= waitingMoney){
            waitingMoney -= nominal
            leftNominals.remove(at: index)
        } else {
            index += 1
        }
        
        if(waitingMoney == 0){
            nominals = leftNominals
            funds -= money
            dailyLimit -= money
            print("Operacja udana")
            return
        }
        
        
    }
    
    if(leftNominals.count == 0){
        throw ATC_Errors.LowMoneyInATC
    } else {
        throw ATC_Errors.NoMatchingNotes
    }
}

print(nominals)

do {
    try withdrawMoney()
} catch{
    print(error)
}

print(nominals)

do {
    try withdrawMoney()
} catch{
    print(error)
}

print(nominals)
