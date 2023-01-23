//
//  main.swift
//  Ex2
//
//  Created by student on 05/12/2022.
//

import Foundation

struct JavelinThrower {
    var id:String
    var throwScores:[Int]
    
    func show(){
        print("Wyniki zawodnika \(id): ",throwScores)
    }
    
    func getAverage() -> Int{
        var average:Int = 0
        for score in throwScores {
            average += score
        }
        return average/throwScores.count
    }
}

var throwers:[JavelinThrower] = []

for i in 1...4{
    var thrower:JavelinThrower = JavelinThrower(id: "Somebody", throwScores: [])
    
    print("Podaj id \(i) zawodnika: ",terminator: "")
    thrower.id = readLine()!
    
    for x in 0..<3 {
        while(true){
            print("Podaj dystans \(x+1) rzutu (w całkowitych metrach): ",terminator: " ")
            guard let temp = Int(readLine()!) else {
                print("To nie liczba")
                continue;
            }
            
            thrower.throwScores.append(temp)
            break;
        }
    }
    
    throwers.append(thrower)
}

print("Zawodnicy przed operacjami")
for thrower in throwers {
    thrower.show()
}

throwers.sort(by: {$0.getAverage() < $1.getAverage()})
throwers.removeFirst()
print("Najlepszy zawodnik: ")
throwers.last!.show()

print("Zawodnicy po usunięciu: ")
for thrower in throwers {
    thrower.show()
}

