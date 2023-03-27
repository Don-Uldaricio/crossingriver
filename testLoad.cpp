#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Load.h"

using namespace std;

int main() {
    const char *fileName = "sistema.txt";
    Load *archivo = new Load("sistema.txt");
    cout << "Cantidad conductores: " << archivo->getDrivers() << endl;
    cout << "Cantidad elementos: " << archivo->getElements() << endl;
    cout << "Tamaño bote: " << archivo->getBoatSize() << endl;
    cout << "Cantidad total: " << archivo->getTotal() << endl;
}