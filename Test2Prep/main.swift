import Foundation

class Punkt: CustomStringConvertible {
    var x:Double
    var y:Double

    init(x: Double, y: Double){
        self.x = x
        self.y = y
    }
    
    public var description: String {return "x: \(x) y: \(y)"}
}

class Dane2P {
    var a:Punkt
    var b:Punkt

    init(a: Punkt, b: Punkt){
        self.a = a
        self.b = b
    }

    func length(a: Punkt,b: Punkt)->Double {
        return sqrt(pow((b.x - a.x),2)+pow((b.y-a.y),2))
    }

    func vector(a: Punkt,b: Punkt)->Punkt {
        return Punkt(x:(b.x-a.x),y:(b.y-a.y))
    }

    func show(){
        print("Punkty: \(a) \(b)|Długość: \(length(a: a, b: b))|Vector: \(vector(a:a,b:b))")
    }
}

class Dane3P {
    var c:Punkt

    init(a: Punkt, b: Punkt, c: Punkt){
        self.c = c
        super.init(a:a,b:b)
    }
}

func canBuildTriangle(p1: Dane2P, p2: Dane2P, p3: Dane2P)->Bool{
    var (l1,l2,l3) = (p1.length(a:p1.a,b:p1.b),p2.length(a:p2.a,b:p2.b),p3.length(a:p3.a,b:p3.b))
    var max = l1

    if(max < l2){
        max = l2
    }
    if(max < l3){
        max = l3
    }

    if(max >= (l1+l2+l3)-max){
        print("Z odcinków o długości \(l1) \(l2) \(l3) nie da się stworzyć trójkąta")
        return false
    } else {
        return true
    }
}

var a = Punkt(x: 5,y: -3)
var b = Punkt(x: 3,y: 2)
var c = Punkt(x: 4,y: 6)
var d = Punkt(x: 3,y: 7)


var p2s:[Dane2P] = [Dane2P(a: a,b: b),Dane2P(a: a,b: c),Dane2P(a: a,b: d),Dane2P(a: b,b: c),Dane2P(a: b,b: d),Dane2P(a: c,b: d)]
for p2 in p2s{
    p2.show()
}

for (i1,x) in p2s.enumerated(){
    for (i2,y) in p2s.enumerated() {
        if(i1 == i2) { continue }

        for (i3,z) in p2s.enumerated() {
            if(i1 == i3 || i2 == i3) { continue }

            if(!canBuildTriangle(p1: x, p2: y, p3: z)) { exit(0) }
        }
    }
}

