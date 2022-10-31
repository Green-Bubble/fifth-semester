#include <iostream>
#include "MeanBuffer.h"
#include "MaxBuffer.h"
#include <iostream>

using namespace std;

int main() {
    MaxBuffer meanBuffer(3);

    meanBuffer.add(123456);
    meanBuffer.add(7);
    meanBuffer.add(1234);
    meanBuffer.add(8);
    meanBuffer.add(67);
    meanBuffer.show();

    cout<<meanBuffer.calculate();

    return 0;
}
