//
//  main.swift
//  Ex5
//
//  Created by student on 05/12/2022.
//

import Foundation

struct Flight{
    var depAirport:[String:String]
    var arrAirpot:[String:String]
    var flightTime:Int
}

var n:Int = 0
var flights:[Flight] = []

while(true){
    print("Podaj liczbę lotów: ",terminator: " ")
    guard let temp = Int(readLine()!) else {
        print("To nie liczba")
        continue;
    }
    
    n = temp;
    break;
}

for i in 0..<n{
    var flight:Flight = Flight(depAirport: [:], arrAirpot: [:], flightTime: 30)
    
    print("Podaj identyfikator lotniska: ")
    flight
    
}
