#include <iostream>
#include "State.h"

using namespace std;

int main() {
    int capacity = 6;
    int nElem = 4;

    int left[4] = {1, 0, 1, 1};
    int right[4] = {0, 0, 0, 0};
    State *s = new State(nElem);
    cout << "Valor decimal left de s: " << s->getDecimalLeft() << endl;
    right[0] = 1;
    right[1] = 1;
    State *s1 = new State(nElem, left, right, 1, s);
    cout << "Valor decimal left de s1: " << s1->getDecimalLeft() << endl;

    cout << "Se imprimen los estados s y s1:" << endl;
    s->print();
    s1->print(); 

    cout << "Ahora se imprime el camino que se sigue hasta s1:" << endl;
    s1->printPath();   
    //delete s;
    return 0;
}