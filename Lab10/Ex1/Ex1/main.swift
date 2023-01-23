//
//  main.swift
//  Ex1
//
//  Created by student on 12/12/2022.
//

import Foundation

func generateNumbers() -> (Int,Int,Int) {
    return (Int.random(in: 1...250),Int.random(in: 1...250),Int.random(in: 1...250))
}

func maxNumber(numbers:(Int,Int,Int)) -> Int {
    var max = numbers.0
    
    if(max < numbers.1){
        max = numbers.1
    }
    
    if(max < numbers.2){
        max = numbers.2
    }
    
    return max
}

func minNumber(numbers:(Int,Int,Int)) -> Int {
    var min = numbers.0
    
    if(min > numbers.1){
        min = numbers.1
    }
    
    if(min > numbers.2){
        min = numbers.2
    }
    
    return min
}

func minAndMaxNumber(numbers:(Int,Int,Int)) -> (min: Int,max: Int) {
    return(minNumber(numbers: numbers),maxNumber(numbers: numbers))
}

var numbers = generateNumbers()

print(numbers)
print(maxNumber(numbers: numbers))
print(minNumber(numbers: numbers))
print(minAndMaxNumber(numbers: numbers))
