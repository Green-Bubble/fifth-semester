//
//  ChristmasTree.swift
//  Ex5
//
//  Created by student on 09/01/2023.
//

import Foundation

class ChristmasTree : Tree {
    var levelsCount:Int
    var trunkHeight:Int
    var decorationsCount:Int
    var decorationsType:Decoration
    
    init(height: Int, type: TreeType, yearOfPlanting: Int,levelsCount: Int,trunkHeight: Int,decorationsCount:Int,decorationsType: Decoration) {
        
        
        
        self.levelsCount = levelsCount
        self.trunkHeight = trunkHeight
        self.decorationsType = decorationsType
        self.decorationsCount = decorationsCount
        
        super.init(height: height, type: type, yearOfPlanting: yearOfPlanting)
    }
    
    override func show() {
        super.show()
        print("Liczba poziomów \(levelsCount)","wysokość pnia \(trunkHeight)","Liczba ozdób \(decorationsCount)",decorationsType)
    }
    
    //layercount = height levelcount = levelscount
    func draw(){
        let length = height * levelsCount
        var starcount = 1
        var spacecount = length
        for _ in 1...height {
            for _ in 1...levelsCount {
                for _ in 1...spacecount{
                    print(" ",terminator: "")
                }
                for _ in 1...starcount {
                    print("*",terminator: "")
                }
                print()
                starcount += 2
                spacecount -= 1
            }
            starcount = starcount - 2
            spacecount = spacecount + 1
            if levelsCount <= 3 {
                starcount -= 2
                spacecount += 1
            } else {
                starcount -= 4
                spacecount += 2
            }
        }
        spacecount = length;
        for _ in 1...trunkHeight { //3 to wysokość pnia
            for _ in 1...spacecount-1 {
                print(" ",terminator: "")
            }
            for _ in 1...3 {
                print("#",terminator: "")
            }
            print()
        }
    }
    
    func drawDecorated(){
        let length = height * levelsCount
        var starcount = 1
        var spacecount = length
        for _ in 1...height {
            for decorations in 1...levelsCount {
                
                var decorationsPositions:[Int] = []
                
                while(decorationsPositions.count < decorations){
                    var takenPos:Bool = false
                    let pos = Int.random(in: 1...starcount)
                    
                    for position in decorationsPositions {
                        if(position == pos){
                            takenPos = true
                            break
                        }
                    }
                    
                    if(!takenPos){
                        decorationsPositions.append(pos)
                    }
                }
                
                for _ in 1...spacecount{
                    print(" ",terminator: "")
                }
                for i in 1...starcount {
                    if(decorationsPositions.contains(i)){
                        print("o",terminator: "")
                    } else {
                        print("*",terminator: "")
                    }
                }
                print()
                starcount += 2
                spacecount -= 1
            }
            starcount = starcount - 2
            spacecount = spacecount + 1
            if levelsCount <= 3 {
                starcount -= 2
                spacecount += 1
            } else {
                starcount -= 4
                spacecount += 2
            }
        }
        spacecount = length;
        for _ in 1...trunkHeight { //3 to wysokość pnia
            for _ in 1...spacecount-1 {
                print(" ",terminator: "")
            }
            for _ in 1...3 {
                print("#",terminator: "")
            }
            print()
        }
    }
    
    func drawDecoratedLessRandom(){
        let length = height * levelsCount
        var starcount = 1
        var spacecount = length
        for _ in 1...height {
            for decorations in 1...levelsCount {
                
                var leftDecorations = decorations
                
                for _ in 1...spacecount{
                    print(" ",terminator: "")
                }
                for i in 1...starcount {
                    let doDec = Int.random(in: 1...starcount+1-i)
                    if(doDec <= leftDecorations){
                        print("o",terminator: "")
                        leftDecorations -= 1
                    } else {
                        print("*",terminator: "")
                    }
                }
                print()
                starcount += 2
                spacecount -= 1
            }
            starcount = starcount - 2
            spacecount = spacecount + 1
            if levelsCount <= 3 {
                starcount -= 2
                spacecount += 1
            } else {
                starcount -= 4
                spacecount += 2
            }
        }
        spacecount = length;
        for _ in 1...trunkHeight { //3 to wysokość pnia
            for _ in 1...spacecount-1 {
                print(" ",terminator: "")
            }
            for _ in 1...3 {
                print("#",terminator: "")
            }
            print()
        }
    }
    
    func decorationsToBuy(){
        var neededDecorations = 0
        
        for i in 1...levelsCount{
            neededDecorations += i
        }
        
        neededDecorations *= height
        
        if(self.decorationsCount >= neededDecorations){
            print("Jest wystarczająco dużo ozdób")
        } else {
            print("Należy dokupić \(neededDecorations - self.decorationsCount) ozdób")
        }
        
        
    }
}
