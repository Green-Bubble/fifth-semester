//
//  main.swift
//  Ex2
//
//  Created by student on 12/12/2022.
//

import Foundation

while(true){
    print("1 - dodanie")
    print("2 - odejmowanie")
    print("3 - mnożenie")
    print("4 - dzielenie")
    print("5 - pierwiastkowanie")
    print("Dowolny - wyjdź")
    print("Wybór: ",terminator: "")

    let choice = readLine()!
    
    switch(choice){
    case "1":
        add()
        break;
    case "2":
        subtract()
        break;
    case "3":
        multiply()
        break;
    case "4":
        divide()
        break;
    case "5":
        squareRoot()
        break;
    default:
        exit(0);
    }
}

func getFloatFromConsole() -> Float{
    while(true){
        print("Podaj liczbę: ")
        guard let temp = Float(readLine()!) else {
            print("To nie jest liczba")
            continue
        }
        
        return temp
    }
}

func add(){
    let numbers = (getFloatFromConsole(),getFloatFromConsole())
    print("Wynik: \(numbers.0 + numbers.1)")
}

func subtract(){
    let numbers = (getFloatFromConsole(),getFloatFromConsole())
    print("Wynik: \(numbers.0 - numbers.1)")
}

func multiply(){
    let numbers = (getFloatFromConsole(),getFloatFromConsole())
    print("Wynik: \(numbers.0 * numbers.1)")
}

func divide(){
    let numbers = (getFloatFromConsole(),getFloatFromConsole())
    if(numbers.1 != 0){
        print("Wynik: \(numbers.0 / numbers.1)")
    } else {
        print("Nie wolno dzielić przez zero")
    }
}

func squareRoot(){
    let number = getFloatFromConsole()
    if(number >= 0){
        print("Wynik: \(sqrt(number))")
    } else {
        print("Nie ma pierwiastka z liczby ujemnej")
    }
}
