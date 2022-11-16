#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <valarray>

using namespace std;

template <typename T>
void showVector(vector<T> v){
    for_each(v.begin(),v.end(),[](T el){
        cout<<el<<" ";
    });
    cout<<endl;
}

int main() {
    srand(time(NULL));

    vector<int> numbers;
    for(int i = 0; i < 50; i++){    //Tworzenie odpowiednich liczb do zaprezentowania działania
        int digits = rand()%10+1;
        int range = pow(10,digits);
        numbers.push_back(rand()%range);
    }

    cout<<"--------------NIEPOSORTOWANE--------------"<<endl;
    showVector(numbers);
    cout<<"--------------POSORTOWANE ROSNACA WEDLUG SUMY CYFR--------------"<<endl;
    sort(numbers.begin(),numbers.end(),[](int n1, int n2){
        int sumN1 = 0, sumN2 = 0;

        while (n1 > 0){
            sumN1 += n1%10;
            n1 /= 10;
        }

        while(n2 > 0){
            sumN2 += n2%10;
            n2 /= 10;
        }

        return sumN1 < sumN2;
    });

    showVector(numbers);
    cout<<"--------------POSORTOWANE MALEJACA WEDLUG LICZBY CYFR--------------"<<endl;
    sort(numbers.begin(),numbers.end(),[](int n1, int n2){
        int amountN1 = 0, amountN2 = 0;

        while (n1 > 0){
            amountN1++;
            n1 /= 10;
        }

        while(n2 > 0){
            amountN2++;
            n2 /= 10;
        }

        return amountN1 > amountN2;
    });

    showVector(numbers);
    return 0;
}

