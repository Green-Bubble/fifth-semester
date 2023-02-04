//
//  main.swift
//  Ex3
//
//  Created by student on 12/12/2022.
//

import Foundation

func getFloatFromConsole(message:String) -> Float{
    while(true){
        print(message)
        guard let temp = Float(readLine()!) else {
            print("To nie jest liczba")
            continue
        }
        
        return temp
    }
}

func getPoint() -> (x:Float,y:Float) {
    return (getFloatFromConsole(message: "Podaj x: "),getFloatFromConsole(message: "Podaj y: "))
}

func Distance(points:((x:Float,y:Float),(x:Float,y:Float))) -> Float {
    return sqrtf(pow((points.1.x-points.0.x), 2)+pow((points.1.y-points.0.y), 2))
}

func GetQuarterIndex(point:(x:Float,y:Float)) -> Int {
    if(point.x >= 0){
        if(point.y >= 0){
            return 1
        } else {
            return 4
        }
    } else {
        if(point.y >= 0){
            return 2
        } else {
            return 3
        }
    }
}

func pointRelationToSquare(point:(x:Float,y:Float),squareCorners:((x:Float,y:Float),(x:Float,y:Float))){
    
}

print("Podaj współrzędne punktów: ")
let points = (getPoint(),getPoint())

print(Distance(points: points))
print("Ćwiartka pierwszego punktu: \(GetQuarterIndex(point: points.0))")

print("Podaj górny prawy róg kwadratu (drugi jest na 0,0): ")
let squareCorners = ((x:0.0,y:0.0),getPoint())
print(squareCorners)

