import Foundation

class Pracownik: Osoba{
    var rokZatrudnienia: Int
    enum stanowisko: Int{
        case mechanik = 1
        case kierownik = 2
        case menedzer = 3
        case prezes = 4
    }
    var stawkaGodzinowa: Double
    var liczbaZrealizowanychGodzin: Int
    
    init(rokZatrudnienia: Int, stawkaGodzinowa: Double, liczbaZrealizowanychGodzin: Int, imie : String, nazwisko: String, rokUrodzenia: Int) {
        self.rokZatrudnienia = rokZatrudnienia
        self.stawkaGodzinowa = stawkaGodzinowa
        self.liczbaZrealizowanychGodzin = liczbaZrealizowanychGodzin
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia)
    }
    
    func ileLatWFirmie()->Int{
        return 2022-rokZatrudnienia
    }
    
    func ileZarobi()->Double{
        return stawkaGodzinowa*Double(liczbaZrealizowanychGodzin)
    }
    
    override func printOsoba() {
        print("")
    }
}
