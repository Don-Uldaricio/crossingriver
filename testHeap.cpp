#include <iostream>
#include "Heap.h"


using namespace std;

int main() {
    int capacity = 6;
    int nElem = 4;
    Heap *hp = new Heap(capacity);

    int left[4] = {1, 1, 1, 1};
    int right[4] = {0, 0, 0, 0};
    State *s = new State(nElem, left, right, nullptr); // new llama al constructor y entrega un puntero
    s->setValue(1);
    right[0] = 1;
    right[1] = 1;
    State *s1 = new State(nElem, left, right, s);
    s1->setValue(3);

    s1->printPath();   

    hp->push(s);
    hp->push(s1);
    hp->data[1]->print();
    
    //delete s;
    return 0;
}