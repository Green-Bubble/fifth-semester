import Foundation

class Prostopadloscian: Prostokat{
    var wysokosc: Double
    init(wysokosc: Double,dlugoscA: Double,dlugoscB: Double) {
        self.wysokosc = wysokosc
        super.init(dlugoscA: dlugoscA, dlugoscB: dlugoscB)
    }
    func poleCalkowite()->Double{
        return super.obliczPole()*2+(dlugoscA*wysokosc)*2+(dlugoscB*wysokosc)*2
    }
    func sumaKrawedzi()->Double{
        return 4*wysokosc + 2*dlugoscB + 2*dlugoscA
    }
    func objetosc()->Double{
        return super.obliczPole()*wysokosc
    }
    override func printProstokat() {
        print("Wysokosc: \(wysokosc), pole Calkowite: \(poleCalkowite()), suma Krawedzi: \(sumaKrawedzi()), objetosc: \(objetosc())")
    }
}
