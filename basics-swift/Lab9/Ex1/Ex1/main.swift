//
//  main.swift
//  Ex1
//
//  Created by student on 05/12/2022.
//

import Foundation

struct ComplexNumber {
    var realPart:Float
    var imaginaryPart:Float
    
    func show(){
        print(self.realPart,self.imaginaryPart)
    }
}

var n1:ComplexNumber = ComplexNumber(realPart:0,imaginaryPart:0)
var n2:ComplexNumber = ComplexNumber(realPart:0,imaginaryPart:0)


while(true){
    print("Podaj część rzeczywistą 1 liczby: ",terminator: " ")
    guard let temp = Float(readLine()!) else {
        print("To nie liczba")
        continue;
    }
    
    n1.realPart = temp;
    break;
}


while(true){
    print("Podaj część urojoną 1 liczby: ",terminator: " ")
    guard let temp = Float(readLine()!) else {
        print("To nie liczba")
        continue;
    }
    
    n1.imaginaryPart = temp;
    break;
}

while(true){
    print("Podaj część rzeczywistą 2 liczby: ",terminator: " ")
    guard let temp = Float(readLine()!) else {
        print("To nie liczba")
        continue;
    }
    
    n2.realPart = temp;
    break;
}


while(true){
    print("Podaj część urojoną 2 liczby: ",terminator: " ")
    guard let temp = Float(readLine()!) else {
        print("To nie liczba")
        continue;
    }
    
    n2.imaginaryPart = temp;
    break;
}

while(true){
    print("Podaj wybór: +, -, *, exit: ",terminator: " ")
    let choice = readLine()!
    
    switch(choice){
    case "+":
        ComplexNumber(realPart:n1.realPart+n2.realPart, imaginaryPart:n1.imaginaryPart+n2.imaginaryPart).show()
        break
    case "-":
        ComplexNumber(realPart:n1.realPart-n2.realPart, imaginaryPart:n1.imaginaryPart-n2.imaginaryPart).show()
        break
    case "*":
        ComplexNumber(realPart: n1.realPart*n2.realPart - n1.imaginaryPart*n2.imaginaryPart, imaginaryPart: n1.realPart*n2.imaginaryPart + n2.realPart*n1.imaginaryPart).show()
        break
    case "exit":
        exit(0)
        break
    default:
        print("Nie istnieje wybor \(choice)")
    }
}
