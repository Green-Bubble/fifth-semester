//
//  Cuboid.swift
//  Ex1
//
//  Created by student on 19/12/2022.
//

import Foundation

class Cuboid : Rectangle {
    var height:Float
    
    init(sides: (Float,Float),height: Float) {
        self.height = height
        super.init(sides: sides)
    }
    
    override func getArea() -> Float {
        return super.getArea()*2 + sides.0 * height * 2 + sides.1 * height * 2
    }
    
    override func getPerimeter() -> Float {
        return sides.0 * 4 + sides.1 * 4 + height * 4
    }
    
    func getVolume() -> Float {
        return super.getArea() * height
    }
    
    override func show() {
        print("Prostopadłościan o krawędziach podstaw ",sides," i wysokości \(height) ma pole całkowite \(getArea()), sumę krawędzi \(getPerimeter()) i objętość \(getVolume())")
    }
}
