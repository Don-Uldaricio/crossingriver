#include <iostream>

using namespace std;

class Operation {
    public:
        int *movement;
        int *drivers;
        int *elements;
        int boatMov; // 0: to left, 1: to right
        int opBoatSize;
        Operation();
        Operation(int *drivers, int *elements, int opBoatSize);
};