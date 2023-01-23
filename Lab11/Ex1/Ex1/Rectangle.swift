//
//  Rectangle.swift
//  Ex1
//
//  Created by student on 19/12/2022.
//

import Foundation

class Rectangle {
    var sides:(Float,Float)
    
    init(sides: (Float, Float)) {
        self.sides = sides
    }
    
    func getArea() -> Float{
        return sides.0 * sides.1
    }
    
    func getPerimeter() -> Float {
        return sides.0 * 2 + sides.1 * 2
    }
    
    func show(){
        print("Prostokąt o bokach ",sides," ma pole \(getArea()) i obwód \(getPerimeter())")
    }
}
