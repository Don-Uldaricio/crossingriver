#include "CrossingRiver.h"
#include <ctime> // la libreria c que permite calcular cosas con el tiempo
// https://cplusplus.com/reference/ctime/
#include <string>


int main() {
    clock_t t_ini, t_fin;
    double secs=0;

    CrossingRiver *cr;
    int k, numVeces;
    string nombreArchivo;

    cout << "Cuantas veces quieres que se resuelva el problema? ";
    cin >> numVeces;

    cout << endl << "Indique el nombre de archivo:  " ;
    cin >> nombreArchivo;

    cout << endl << "Resolviendo el problema " << nombreArchivo <<", "<< numVeces << " veces..." << endl;
    
    for (k=0; k<numVeces; k++) {
        cr = new CrossingRiver(nombreArchivo);
        t_ini = clock();
        cr->solve();
        t_fin = clock();
        secs = secs + (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
        delete cr;
    }
    cout << endl << "Tiempo promedio: " << secs/numVeces << " segundos" << endl;
    
    return 0;
}