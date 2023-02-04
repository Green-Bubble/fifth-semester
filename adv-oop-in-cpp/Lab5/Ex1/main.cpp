#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void showOrderedCollection(T collection){
    for_each(collection.begin(),collection.end(),[](auto value){
        cout<<value<<" ";
    });
    cout<<endl;
}

pair<int, int> findDuplicate(vector<int> v){
    set<int> st;
    pair<int, int> result;
    for_each(v.begin(),v.end(),[&](int number){
        pair<set<int>::iterator , bool> didSucceed = st.insert(number);
        if(!didSucceed.second){
            result.first = *didSucceed.first;
        }
    });
    result.second = st.size();

    return result;
}



int main() {
    srand(time(NULL));

    vector<int> vc;

    int duplicatedNumber = rand()%30;
    for(int i = 0; i < 30; i++){
        vc.push_back(i);
    }
    vc.push_back(duplicatedNumber);

    //shuffle(vc.begin(), vc.end(),default_random_engine(0));
    showOrderedCollection(vc);

    auto result = findDuplicate(vc);
    cout<<"Duplikat: "<<result.first<<" liczba unikatowych: "<<result.second;

    return 0;
}
