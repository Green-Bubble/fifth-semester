#include <iostream>
#include <regex>
#include <fstream>

int main() {
    std::ifstream fileIf;
    std::regex comments ("//.*");
    fileIf.open("/home/marcinskic/repos/adv-oop-in-cpp/Lab8/Ex1/kod.txt",std::ios::in);

    if(fileIf.is_open()){
        std::string line;
        while(!fileIf.eof()){
            getline(fileIf, line);

            std::cout<<std::regex_replace(line,comments,"")<<std::endl;
        }

        fileIf.close();
    } else {
        std::cerr<<"Plik nie istnieje";
    }

    return 0;
}
