#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
void showOrderedCollection(T collection){
    for_each(collection.begin(),collection.end(),[](auto value){
        cout<<value<<" ";
    });
    cout<<endl;
}

template <typename T>
void XOR(set<T> s1, set<T> s2){
    set<T> temp_union;
    set<T> temp_intersection;
    set<T> result;

    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(temp_union,temp_union.begin()));
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(temp_intersection,temp_intersection.begin()));
    set_difference(temp_union.begin(),temp_union.end(),temp_intersection.begin(),temp_intersection.end(), inserter(result,result.begin()));

    showOrderedCollection(result);

}

int main() {
    set<int> s1;
    set<int> s2;

    for(int i = 0; i < 30; i++){
        s1.insert(i);
        s2.insert(i+20);
    }
    showOrderedCollection(s1);
    showOrderedCollection(s2);

    XOR(s1,s2);
    return 0;
}
