#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Load.h"

using namespace std;

Load::Load(const char *fileName) {
    ifstream *input = new ifstream(fileName); // abrir el archivo
    if (input->is_open()) { // verificar que el archivo se abrio correctamente
        std::cout << "archivo abierto" << std::endl;

    } else {
        std::cout << "archivo no encontrado" << std::endl;
        exit(1);
    }

    string line; // linea de texto
    stringstream ss; // stream de caracteres

    // variables a leer del archivo
    int C,I,b,N; // cantidad de conductores, cantidad de item, capacidad del bote, cantidad total de item mas conductores
    int leftRestNum, rightRestNum; // cantidad de restricciones de cada lado
    int **restriccionesIzq, **restriccionesDer; // matriz de restricciones de cada lado


    // leer la primera linea
    getline(*input, line);
    ss << line; // copiar la linea al stream
    ss >> C >> I >> b; // leer los datos del stream
    N = C + I;
    //cout <<"C:"<< C << " I:" << I << " b:" << b << endl;

    this->driversNum = C;
    this->elementsNum = I;
    this->boatSize = b;
    this->totalNum = N;

    // leer la segunda linea
    getline(*input, line);
    leftRestNum=atoi(line.c_str()) ; // c_str convierte el string a un arreglo de caracteres
    this->leftRestNum = leftRestNum;
    this->leftRest = new int*[leftRestNum]; // crear la matriz de restricciones
    for (int i = 0; i < leftRestNum; i++) {
        leftRest[i] = new int[N];
        for (int j = 0; j < N; j++) {
            leftRest[i][j] = 0;
        }
    }

    // leer las restricciones del lado izquierdo
    for (int i = 0; i < leftRestNum; i++) {
        getline(*input, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            leftRest[i][a-1] = 1; // a-1 porque los indices empiezan en 0
        }
    }
    
    
    // leer las restricciones del lado derecho
    getline(*input, line);
    ss.clear(); // limpiar el stream de caracteres
    ss << line; // copiar la linea al stream
    ss >> rightRestNum;
    this->rightRestNum = rightRestNum;
    this->rightRest = new int*[rightRestNum]; // crear la matriz de restricciones
    for (int i = 0; i < rightRestNum; i++) {
        rightRest[i] = new int[N];
        for (int j = 0; j < N; j++) { // inicialmente en 0
            rightRest[i][j] = 0;
        }
    }

    for (int i = 0; i < rightRestNum; i++) {
        getline(*input, line);
        ss.clear(); // limpiar el stream de caracteres
        ss << line; // copiar la linea al stream
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            rightRest[i][a-1] = 1; // recuerden que los elementos de los archivos empiezan en 1, pero los indices en 0
        }
    }

    // cerrar el archivo
    input->close();
}

int Load::getDrivers() {
    return this->driversNum;
}

int Load::getElements() {
    return this->elementsNum;
}

int Load::getTotal() {
    return this->totalNum;
}

int Load::getBoatSize() {
    return this->boatSize;
}

int Load::getLeftRestNum() {
    return this->leftRestNum;
}

int Load::getRightRestNum() {
    return this->rightRestNum;
}

int **Load::getLeftRest() {
    return this->leftRest;
}

int **Load::getRightRest() {
    return this->rightRest;
}

void Load::printMatrix() {
    cout<<"restriccionesIzq:"<<endl;
    for(int i=0;i<this->leftRestNum;i++){
        for(int j=0;j<this->totalNum;j++){
            cout<<this->leftRest[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"restriccionesDer:"<<endl;
    for(int i=0;i<this->leftRestNum;i++){
        for(int j=0;j<this->totalNum;j++){
            cout<<this->rightRest[i][j]<<" ";
        }
        cout<<endl;
    }
}
