#include <iostream>

using namespace std;

/*
    * Operation class:
    * This class is used to representate an operation (movement) applied to
    * State class to change the state by moving the elements of left/right 
    * arrays to the opposite.
*/
class Operation {
    public:
        int *movement; // Arreglo donde cada índice
        int nTotal;

        // Constructors
        Operation();
        Operation(int *m, int size);
};