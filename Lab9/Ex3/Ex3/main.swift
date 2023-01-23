//
//  main.swift
//  Ex3
//
//  Created by student on 05/12/2022.
//

import Foundation

var exampleCars = ["Honda","Bugatti","Toyota","Koeniggseg","Saab","Fiat","Ford","Mazda","Volkswagen","Audi"]
var cars = Set<String>()

exampleCars.shuffle()
for i in 0...5 {
    cars.insert(exampleCars[i])
}

print(cars)

while(true){
    print("Podaj samochód do usunięcia: ")
    let car = readLine()!

    guard let _ = cars.remove(car) else {
        print("Nie było takiego samochodu")
        continue
    }
    
    break
}

print(cars)
