#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "Load.h"

using namespace std;

/// @brief Constructor of Load that initialize the attributes of Load Class
/// @param fileName const char that represent the file name
Load::Load(const char *fileName) {
    ifstream *input = new ifstream(fileName); // abrir el archivo
    if (input->is_open()) { // verificar que el archivo se abrio correctamente
        std::cout << "SISTEMA LEÍDO CORRECTAMENTE." << std::endl;

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
    this->leftRest = new int[leftRestNum]; // crear el arreglo de restricciones
    for (int i = 0; i < leftRestNum; i++) {
        leftRest[i] = 0;
    }

    // leer las restricciones del lado izquierdo
    for (int i = 0; i < leftRestNum; i++) {
        getline(*input, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        int a;
        while (ss >> a) { // mientras no termine esta linea
            leftRest[i] += pow(2, N - a);
        }
    }
    
    
    // leer las restricciones del lado derecho
    getline(*input, line);
    ss.clear(); // limpiar el stream de caracteres
    ss << line; // copiar la linea al stream
    ss >> rightRestNum;
    this->rightRestNum = rightRestNum;
    this->rightRest = new int[rightRestNum]; // crear la matriz de restricciones
    for (int i = 0; i < rightRestNum; i++) {
        rightRest[i] = 0;
    }

    for (int i = 0; i < rightRestNum; i++) {
        getline(*input, line);
        ss.clear(); // limpiar el stream de caracteres
        ss << line; // copiar la linea al stream
        int a;
        while (ss >> a) { // mientras no termine esta linea
            rightRest[i] += pow(2, N - a);
        }
    }

    // cerrar el archivo
    input->close();
}

/// @brief Get the number of drivers
/// @return Integer that represents the number of drivers
int Load::getDrivers() {
    return this->driversNum;
}

/// @brief Get the number of elements of the problem
/// @return Integer that represent the number of elements
int Load::getElements() {
    return this->elementsNum;
}

/// @brief Get the number of total elements of the problem
/// @return Integer that represent the number of total elements of the problem
int Load::getTotal() {
    return this->totalNum;
}

/// @brief Get the boat size of the problem
/// @return Integer that represent the boat size of the problem
int Load::getBoatSize() {
    return this->boatSize;
}

/// @brief Shows the restrictions of the problem in screen
void Load::printRest() {
    cout<<"Left Restrictions:"<<endl;
    for(int i = 0; i < this->leftRestNum; i++) {
        cout << leftRest[i] << " ";
    }
    cout << endl;

    cout<<"Right Restrcitions:"<<endl;
    for(int i=0;i<this->rightRestNum;i++){
        cout << rightRest[i] << " ";
    }
}
