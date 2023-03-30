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
}