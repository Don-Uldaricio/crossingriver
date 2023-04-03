#include <iostream>
#include <cmath>
#include <string>
#include "Heap.h"
#include "Operation.h"

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

        CrossingRiver(string fileName);
        bool solve();
        void generateOperations(int *arr, int nElem, int index);
        State *moveToLeft(State *s, Operation *op);
        State *moveToRight(State *s, Operation *op);
        bool isClosed(State *s);
        bool canMoveToLeft(State *s, Operation *op);
        bool canMoveToRight(State *s, Operation *op);
        bool checkRestriction(State *s);
        bool validOp(int *arr);
        void printSolutionPath(State *s);
};