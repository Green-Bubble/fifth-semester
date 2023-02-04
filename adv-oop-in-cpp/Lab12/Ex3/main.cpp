#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <tuple>

using namespace std;

tuple<int,float,string> processStrings(vector<string> strings){
    tuple<int,float,string> result = make_tuple(strings[0].length(),0,strings[0]);

    get<0>(result) = min_element(strings.begin(),strings.end(),[](string s1,string s2){
        return s1.length() < s2.length();
    })->length();

    get<1>(result) = (float)accumulate(strings.begin(),strings.end(),0,[](int init,string s){
       return init+s.length();
    })/(float)strings.size();

    get<2>(result) = *max_element(strings.begin(),strings.end(),[](string s1,string s2){
        return s1.length() < s2.length();
    });

    /*std::for_each(strings.begin(), strings.end(),[&result](string s){
        if(s.length() < get<0>(result)){
            get<0>(result) = s.length();
        }

        get<1>(result) += (float)s.length();

        if(s.length() > get<2>(result).length()){
            get<2>(result) = s;
        }
    });

    get<1>(result) /= (float)strings.size();*/

    return result;
}

int main() {
    vector<string> strings;

    strings.push_back("Hello, World!");
    strings.push_back("Money");
    strings.push_back("Goodbye Yellow Brick Road");
    strings.push_back("Time");
    strings.push_back("Epitaph");
    strings.push_back("One");

    auto result = processStrings(strings);
    cout<<"Dlugosc najkrotszego napisu: "<<get<0>(result)<<endl;
    cout<<"Srednia dlugosc napisu: "<<get<1>(result)<<endl;
    cout<<"Najdluzszy napis: "<<get<2>(result)<<endl;

    return 0;
}

