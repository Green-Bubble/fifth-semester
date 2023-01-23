import Foundation

enum KierunekStudiow : String, CaseIterable{
    case Informatyka
    case FiR
}

class Student: Osoba{
    var numerIndeksu: Int
    var rokStudiow: Int
    var oceny: [Int]
    var kierunek : KierunekStudiow
    init(numerIndeksu: Int, rokStudiow: Int, oceny: [Int], kierunek: KierunekStudiow, imie: String, nazwisko: String, rokUrodzenia: Int) {
        self.numerIndeksu = numerIndeksu
        self.rokStudiow = rokStudiow
        self.oceny = oceny
        self.kierunek = kierunek
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia)
    }
    func srednia()->Double{
        var srednia = 0.0
        for i in oceny{
            srednia = srednia + Double(i);
        }
        return srednia/5.0
    }
    override func printOsoba() {
        print("\(imie) \(nazwisko), lat: \(obliczWiek()), kierunek: \(kierunek), srednia: \(srednia())")
    }
}
