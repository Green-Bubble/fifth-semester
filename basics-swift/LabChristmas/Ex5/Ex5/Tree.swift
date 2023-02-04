//
//  Tree.swift
//  Ex5
//
//  Created by student on 09/01/2023.
//

import Foundation

class Tree {
    var height:Int
    var type:TreeType
    var yearOfPlanting:Int
    
    init(height: Int, type: TreeType, yearOfPlanting: Int) {
        self.height = height
        self.type = type
        self.yearOfPlanting = yearOfPlanting
    }
    
    func show(){
        print("Wysokość \(height)",type,yearOfPlanting)
    }
}
