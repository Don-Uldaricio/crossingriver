#include <iostream>

using namespace std;

class Operation {
    public:
        int *drivers;
        int *elements;
        int opBoatSize;
        Operation();
        Operation(int *drivers, int *elements, int opBoatSize);
};