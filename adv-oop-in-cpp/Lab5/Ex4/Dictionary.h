//
// Created by marcinskic on 11/22/22.
//

#ifndef EX4_DICTIONARY_H
#define EX4_DICTIONARY_H
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Dictionary {
private:
    map<string,string> words;
public:
    Dictionary();
    bool add(string word,string translation);
    bool deleteWord(string word);
    void show();
    string getTranslation(string word);
    void showSortedByTranslationDesc();
};


#endif //EX4_DICTIONARY_H
