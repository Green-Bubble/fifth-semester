#include <iostream>
#include "Dictionary.h"

using namespace std;
int main() {
    Dictionary dictionary = *(new Dictionary());
    cout<<"Czy udalo sie dodac samochod: "<<dictionary.add("samochod","car")<<endl;
    cout<<"Czy udalo sie dodac samochod: "<<dictionary.add("samochod","auto")<<endl;
    dictionary.add("drzewo","tree");
    dictionary.add("drewno","wood");
    dictionary.add("kwiat","flower");

    cout<<"Czy usunieto samochod: "<<dictionary.deleteWord("samochod")<<endl;
    cout<<"Czy udalo sie dodac samochod po usunieciu: "<<dictionary.add("samochod","auto")<<endl;

    cout<<"Tlumaczenie slowa [samochod]: "<<dictionary.getTranslation("samochod")<<endl;

    dictionary.show();
    dictionary.showSortedByTranslationDesc();

    return 0;
}
