#include <iostream>
#include "Heap.h"
#include "Operation.h"

using namespace std;

class CrossingRiver {
    private:
        Heap *open;
        Heap *closed;
        Heap *operations;
    public:
        CrossingRiver();
        void solve();
        State move(Operation *op);
        bool canMove();
};