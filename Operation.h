#include <iostream>

using namespace std;

class Operation {
    public:
        int *movement; // Arreglo donde cada índice
        int nDrivers;
        int nElements;
        int opBoatSize;
        Operation();
        Operation(int *movement);
};