//
//  main.swift
//  Ex3
//
//  Created by student on 16/01/2023.
//

import Foundation

enum CalculationErrors : Error {
    case DividedByZero
    case SquaredNegative
}

guard let a = Float(readLine()!) else {
    fatalError("To musi być liczba")
}

guard let b = Float(readLine()!) else {
    fatalError("To musi być liczba")
}

func printBasicOperaions(a: Float, b:Float) throws {
    print(a+b)
    print(a-b)
    print(a*b)
    guard b != 0 else {
        throw CalculationErrors.DividedByZero
    }
    print(a/b)
    guard a > 0 else {
        throw CalculationErrors.SquaredNegative
    }
    print(sqrt(a))
}

do {
    try printBasicOperaions(a: a, b: b)
} catch CalculationErrors.DividedByZero {
    print("Podano zero jako dzielnik!")
} catch CalculationErrors.SquaredNegative {
    print("Podano pierwszą liczbę (pierwiastkowaną) ujemną!")
}
