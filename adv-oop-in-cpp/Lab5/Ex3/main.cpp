#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
void showDictionaryCollection(T collection){
    for_each(collection.begin(),collection.end(),[](auto value){
        cout<<"Key: "<<value.first<<" Value:"<<value.second<<endl;
    });
    cout<<endl;
}

map<char,int> stringToMapWithCountedChars(string s){
    map<char,int> charsMap;
    for_each(s.begin(),s.end(),[&](char c){
        if(charsMap.find(c) != charsMap.end()){
            charsMap[c]++;
        } else {
            charsMap[c] = 1;
        }
    });

    return charsMap;
}

char findExtraLetter(map<char, int> map1, map<char, int> map2){

    char c = '?';

    if(map1.size() < map2.size()){
        swap(map1,map2);
    }

    showDictionaryCollection(map1);
    showDictionaryCollection(map2);

    for_each(map1.begin(),map1.end(),[&](auto valueKey){
       if(map2.find(valueKey.first) == map2.end()){
           c = valueKey.first;
       } else if(map2[valueKey.first] != valueKey.second){
           c = valueKey.first;
       }
    });

    return c;
}

int main() {

    string s1 = "kot ma ala";
    string s2 = "ala ma kota";
    string s3 = "ala ma koty";

    auto map1 = stringToMapWithCountedChars(s1);
    auto map2 = stringToMapWithCountedChars(s2);
    auto map3 = stringToMapWithCountedChars(s3);

    showDictionaryCollection(map1);

    cout<<"Dodatkowy znak: "<<findExtraLetter(map2,map1);

    return 0;
}
