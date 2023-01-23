//
//  Numbers.swift
//  Ex2
//
//  Created by student on 16/01/2023.
//

import Foundation

protocol RandomGenerator {
    func generateInt()->Int
}

class Numbers : RandomGenerator {
    var a:Int = 0
    var b:Int = 0
    
    init() {
        a = generateInt()
        b = generateInt()
    }
    
    func generateInt() -> Int {
        return Int.random(in: 0...1000)
    }
    
    func show(){
        print(a,b)
    }
    
    func power(p: Int){
        a = Int(pow(Double(a), Double(p)))
    }
}
