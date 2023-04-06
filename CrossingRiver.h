#include <iostream>
#include <cmath>
#include <string>
#include "Heap.h"
#include "Operation.h"

using namespace std;

/*
    * CrossingRiver class:
    * This class is used to solve the crossing river problem, by reading the file and
    * initilizes the important values.
    * The problem is represented by a Heap with open/closed States and all the attributes
    * like amount of drivers, elements, and boat size, among others.
*/
class CrossingRiver {
    public:
        Heap *open;
        Heap *closed;
        Operation **operations;
        int nElem;
        int nDrivers;
        int nTotal;
        int boatSize;
        int nOperations;
        int nLeftRestrictions;
        int nRightRestrictions;
        int *leftRestrictionsId; // Binary Array into decimal number
        int *rightRestrictionsId; // Binary Array into decimal number

        // Constructor
        CrossingRiver(string fileName);

        // Other methods
        bool solve();
        void generateOperations(int *arr, int nElem, int index, int b, int ones);
        State *moveToLeft(State *s, Operation *op);
        State *moveToRight(State *s, Operation *op);
        bool isClosed(State *s);
        bool canMoveToLeft(State *s, Operation *op);
        bool canMoveToRight(State *s, Operation *op);
        bool checkRestriction(State *s);
        bool validOp(int *arr);
        void printSolutionPath(State *s);
};