import Foundation

class Prostokat{
    var dlugoscA: Double
    var dlugoscB: Double
    init(dlugoscA: Double, dlugoscB: Double) {
        self.dlugoscA = dlugoscA
        self.dlugoscB = dlugoscB
    }
    func obliczPole()->Double{
        return dlugoscA*dlugoscB
    }
    func obliczObwod()->Double{
        return dlugoscB*2+dlugoscA*2
    }
    func printProstokat(){
        print("Bok A: \(dlugoscA), bok B: \(dlugoscB), pole: \(obliczPole()), obwod: \(obliczObwod())")
    }
    
}
