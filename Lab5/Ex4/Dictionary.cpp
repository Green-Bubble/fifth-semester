//
// Created by marcinskic on 11/22/22.
//


#include "Dictionary.h"

Dictionary::Dictionary() {

}

bool Dictionary::add(string word, string translation) {
    if(words.find(word) != words.end()){
        return false;
    }

    words[word] = translation;
    return true;
}

bool Dictionary::deleteWord(string word) {
    int erased = words.erase(word);
    return erased;
}

void Dictionary::show() {
    for_each(words.begin(),words.end(),[](auto value){
        cout<<"Key: "<<value.first<<" Value:"<<value.second<<endl;
    });
    cout<<endl;
}

string Dictionary::getTranslation(string word) {
    return words[word];
}

void Dictionary::showSortedByTranslationDesc() {
    vector<string> translations;
    //vector<string> keys;
    for_each(words.begin(),words.end(),[&](auto value){
        //keys.push_back(value.first);
        translations.push_back(value.second);
    });

    sort(translations.begin(), translations.end());

    cout<<"Tlumaczenia posortowane: ";
    for_each(translations.rbegin(), translations.rend(), [&](string translation){
        cout<<translation<<" ";
    });
    cout<<endl;

    /*auto keyIt = keys.begin();
    for(auto tranIt = translations.rbegin(); tranIt < translations.rend(); tranIt++){
        cout<<""
        keyIt++;
    }

    */
}
