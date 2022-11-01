#include <iostream>
#include "MeanBuffer.h"
#include "MaxBuffer.h"
#include <iostream>

using namespace std;

int main() {
    MeanBuffer meanBuffer(5);

    meanBuffer.add(123456);
    meanBuffer.add(7);
    meanBuffer.add(1234);
    meanBuffer.add(8);
    meanBuffer.add(67);
    meanBuffer.show();
    cout<<"Average: "<<meanBuffer.calculate()<<endl;

    MaxBuffer maxBuffer(3);
    maxBuffer.add(123456);
    maxBuffer.add(7);
    maxBuffer.add(1234);
    maxBuffer.add(8);
    maxBuffer.add(67);
    maxBuffer.show();
    cout<<"Max: "<<maxBuffer.calculate()<<endl;

    return 0;
}
