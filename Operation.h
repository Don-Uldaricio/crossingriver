#include <iostream>

using namespace std;

class Operation {
    public:
        int *movement; // Arreglo donde cada índice
        int nTotal;
        Operation();
        Operation(int *m, int size);
};