#include <iostream>
#include <cmath>
#include "Heap.h"
#include "Operation.h"
#include "Load.h"

using namespace std;

class CrossingRiver {
    public:
        Heap *open;
        Heap *closed;
        Operation *operations[1000];
        int nElem;
        int nDrivers;
        int nTotal;
        int boatSize;
        int nOperations;

        CrossingRiver();
        void solve();
        void addOpen(State *s);
        void addClosed(State *s);
        void generateOperations(int *arr, int nElem, int index);
        State *deleteOpen();
        State *move(Operation *op);
        bool canVisite(State *s, Operation *op);
        bool validOp(int *arr);
};