//
//  ComplexNumOperations.swift
//  Ex1
//
//  Created by student on 16/01/2023.
//

import Foundation


protocol ComplexNumber {
    var re:Float {get set}
    var im:Float {get set}
}

class ComplexNumOperations : ComplexNumber {
    var re: Float
    var im: Float
    
    init(re: Float, im: Float){
        self.re = re
        self.im = im
    }
    
    func add(a: ComplexNumOperations, b: ComplexNumOperations) -> ComplexNumOperations{
        a.re = a.re + b.re
        a.im = a.im + b.im
        return a
    }
    
    func subtract(a: ComplexNumOperations, b: ComplexNumOperations) -> ComplexNumOperations {
        a.re = a.re - b.re
        a.im = a.im - b.im
        
        return a
    }
    
    func show(){
        print(re," ",im)
    }
}
