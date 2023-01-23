//
//  main.swift
//  Ex5
//
//  Created by student on 09/01/2023.
//

enum Decoration {
    case Ball
    case Candy
    case Gingerbread
    case Toy
}

enum TreeType {
    case Leafy
    case Pinophytina
}

func rysujChoinke(layercount:Int, levelcount:Int) {
    var length = layercount * levelcount
    var starcount = 1
    var spacecount = length
    for _ in 1...layercount {
    for _ in 1...levelcount {
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
    if levelcount <= 3 {
    starcount -= 2
    spacecount += 1
    } else {
    starcount -= 4
    spacecount += 2
    }
    }
    spacecount = length;
    for _ in 1...3 { //3 to wysokość pnia
    for _ in 1...spacecount-1 {
    print(" ",terminator: "")
    }
    for _ in 1...3 {
    print("#",terminator: "")
    }
    print()
    }
}

let chrTree = ChristmasTree(height: 3, type: TreeType.Pinophytina, yearOfPlanting: 1999, levelsCount: 5, trunkHeight: 6,decorationsCount: 34, decorationsType: Decoration.Candy)

chrTree.show()
chrTree.drawDecorated()
print("Aby tak udekorować drzewo")
chrTree.decorationsToBuy()

chrTree.drawDecoratedLessRandom()
