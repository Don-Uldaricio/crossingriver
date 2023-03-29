#include <iostream>
#include "Heap.h"
#include "Operation.h"
#include "Load.h"

using namespace std;

class CrossingRiver {
    public:
        Heap *open;
        Heap *closed;
        Operation **operations;
        CrossingRiver(Load *file);
        void solve();
        void addOpen(State *s);
        void addClosed(State *s);
        State *deleteOpen();
        State *move(Operation *op);
        bool canVisite(State *s, Operation *op);
};