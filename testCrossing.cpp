#include <iostream>
#include <string>
#include "CrossingRiver.h"

using namespace std;

int main() {
    string fileName = "sistema.txt";
    CrossingRiver *cr = new CrossingRiver(fileName);
    cout << "drivers: " << cr->nDrivers << endl; 
    cout << "elementos: " << cr->nElem << endl;
    cout << "tamaño bote: " << cr->boatSize << endl;

    cr->solve();
}