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
        int nLeftRestrictions;
        int nRightRestrictions;
        int *leftRestrictionsId; // Binary Array into decimal number
        int *rightRestrictionsId; // Binary Array into decimal number

        CrossingRiver();
        void solve();
        void addOpen(State *s);
        void addClosed(State *s);
        void generateOperations(int *arr, int nElem, int index);
        State *deleteOpen();
        void moveToLeft(State *s, Operation *op);
        void moveToRight(State *s, Operation *op);
        bool isClosed(State *s);
        bool canMoveToLeft(State *s, Operation *op);
        bool canMoveToRight(State *s, Operation *op);
        bool checkRestriction(State *s);
        bool canVisite(State *s, Operation *op);
        bool validOp(int *arr);
};