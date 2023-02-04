#include <iostream>

int main() {
    std::cin.exceptions(std::istream::failbit);

    int sum = 0,number;

    while(sum != 21){
        try{
            std::cout<<"Podaj numer: ";
            std::cin>>number;
            if((sum+number) > 21){
                throw -1;
            }
            sum += number;
        } catch (const std::ios::failure &){
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Podaj liczbe, nie znak"<<std::endl;
        } catch (int w){
            std::cout<<"Przekroczono 21, spróbuj podać jeszcze raz"<<std::endl;
        }
    }

    return 0;
}
