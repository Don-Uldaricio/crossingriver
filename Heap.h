#include <iostream>
#include "State.h"
using namespace std;

/*
    * Heap class:
    * This class is used to representate a Heap (a binary tree) where
    * each node is a State class, it means, a tree of States.
*/
class Heap {
    public:
        State **data;
        int size; // current size
        int capacity; // max size

        // Constructor
        Heap(int capacity);

        // Destructor
        ~Heap();

        // Other methods
        void swap(int i, int j);
        int left_idx(int i);
        int right_idx(int i);
        int parent_idx(int i);
        State* pop();
        void push(State *s);
        void heapify(int i);
};