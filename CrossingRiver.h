#include <iostream>
#include "Heap.h"
#include "Operation.h"
#include "Load.h"

using namespace std;

class CrossingRiver {
    public:
        Heap *open;
        Heap *closed;
        Heap *operations;
        CrossingRiver(Load *file);
        void solve();
        State *addState(State *s);
        State *move(Operation *op);
        bool canMove(State *s);
};