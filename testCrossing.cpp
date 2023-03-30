#include <iostream>
#include "CrossingRiver.h"

using namespace std;

int main() {
    CrossingRiver *cr = new CrossingRiver();
    cout << "drivers: " << cr->nDrivers << endl; 
    cout << "elementos: " << cr->nElem << endl;
    cout << "total: " << cr->nTotal << endl;
    cout << "tamaño bote: " << cr->boatSize << endl;
    cout << "n operaciones: " << cr->nOperations << endl;

    cr->solve();
    cout << "n operaciones: " << cr->nOperations << endl;
    cout << endl << "Operaciones: " << endl;
    for (int i = 0; i < cr->nOperations; i++) {
        for (int j = 0; j < cr->nTotal; j++) {
            cout << cr->operations[i]->movement[j] << " ";
        }
        cout << endl;
    }
}