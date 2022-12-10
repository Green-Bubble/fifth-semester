#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    //students.sort (by: { $0.average < $1.average})

    std::vector<int> inty = {5,34,123,65,3,12,-124};
    int granica = 5;

    std::cout<<*std::find_if(inty.begin(),inty.end(),[&](int a1){
        return a1 = granica;
    });

    std::for_each(inty.begin(),inty.end(),[](int el){
        std::cout<<el<<" ";
    });
    return 0;
}
