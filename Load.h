#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Load {
    public:
        int driversNum;
        int elementsNum;
        int boatSize;
        int totalNum;
        int leftRestNum;
        int rightRestNum;
        int **leftRest;
        int **rightRest;
        Load(const char *fileName); // Constructor
        int getDrivers(); // Obtener cantidad de conductores
        int getElements(); // Obtener cantidad de elementos
        int getTotal(); // Obtener cantidad de total c+e
        int getBoatSize();
        int getLeftRestNum();
        int getRightRestNum();
        int **getLeftRest();
        int **getRightRest();
        void printMatrix();
};