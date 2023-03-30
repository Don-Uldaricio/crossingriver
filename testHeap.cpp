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
    State *s1 = new State(nElem, left, right, s);

    //s1->printPath();   
    cout << "tamaño heap: " << hp->size << endl;
    hp->push(s);
    hp->push(s1);
    for (int i = 0; i < hp->size; i++) {
        hp->data[i]->print();
    }
    cout << "tamaño heap: " << hp->size << endl;
    cout << hp->pop()->getDistance() << endl;
    cout << hp->pop()->getDistance() << endl;
    
    //delete s;
    return 0;
}