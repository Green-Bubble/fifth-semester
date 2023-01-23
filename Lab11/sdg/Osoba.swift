import Foundation

class Osoba{
    var imie: String = ""
    var nazwisko: String = ""
    var rokUrodzenia: Int = 0
    
    init(imie: String, nazwisko: String, rokUrodzenia: Int) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rokUrodzenia = rokUrodzenia
    }
    
    func obliczWiek()-> Int{
        return 2022-rokUrodzenia
    }
    func printOsoba(){
        print("\(imie), \(nazwisko), lat: \(obliczWiek())")
    }
}
