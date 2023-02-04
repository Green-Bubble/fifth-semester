//
//  main.swift
//  Ex4
//
//  Created by student on 12/12/2022.
//

import Foundation

func getIntFromConsole(message:String) -> Int{
    while(true){
        print(message)
        guard let temp = Int(readLine()!) else {
            print("To nie jest liczba")
            continue
        }
        
        return temp
    }
}

func getArrayFromConsole(size:Int) -> [Int]{
    var array:[Int] = []
    
    for i in 1...size {
        array.append(getIntFromConsole(message: "Podaj \(i) liczbę: "))
    }
    
    return array
}

func printArray(array:[Int]){
    print(array)
}

func minInArray(array:[Int]) -> (index:Int,value:Int){
    let index = array.indices.min(by: {array[$0] < array[$1]})!
    return (index,array[index])
}

func maxInArray(array:[Int]) -> (index:Int,value:Int){
    let index = array.indices.max(by: {array[$0] < array[$1]})!
    return (index,array[index])
}

func swapMinWithMax(array: inout [Int]){
    let minIndex = minInArray(array: array).index
    let maxIndex = maxInArray(array: array).index
    
    array.swapAt(minIndex, maxIndex)
}

func averageInArray(array:[Int]) -> Int{
    let sum = array.reduce(0, +)
    return sum/array.count
}

var array = getArrayFromConsole(size: 3)
print(array)
print("Najmniejszy element w tablicy: \(minInArray(array: array))")
swapMinWithMax(array: &array)
print("Po swapie: ")
print(array)
print("Średnia arytmetyczna: ")
print(averageInArray(array: array))
