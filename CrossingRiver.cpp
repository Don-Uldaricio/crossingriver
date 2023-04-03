#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "CrossingRiver.h"

using namespace std;

/// @brief Constructor of CrossingRiver that initialize all attributes of the problem.
/// @param fileName String that represents file name of problem
CrossingRiver::CrossingRiver(string fileName) {
    ifstream *input = new ifstream(fileName); // abrir el archivo
    if (input->is_open()) { // verificar que el archivo se abrio correctamente
        std::cout << "PROBLEM READ SUCCESFULLY." << std::endl;

    } else {
        std::cout << "FILE NOT FOUND." << std::endl;
        exit(1);
    }

    string line; // linea de texto
    stringstream ss; // stream de caracteres

    // variables a leer del archivo
    int C,I,b,N; // cantidad de conductores, cantidad de item, capacidad del bote, cantidad total de item mas conductores
    int leftRestNum, rightRestNum; // cantidad de restricciones de cada lado

    // leer la primera linea
    getline(*input, line);
    ss << line; // copiar la linea al stream
    ss >> C >> I >> b; // leer los datos del stream
    N = C + I;

    this->nDrivers = C;
    this->nElem = I;
    this->boatSize = b;
    this->nTotal = N;

    // leer la segunda linea
    getline(*input, line);
    leftRestNum=atoi(line.c_str()) ; // c_str convierte el string a un arreglo de caracteres
    this->nLeftRestrictions = leftRestNum;
    this->leftRestrictionsId = new int[leftRestNum]; // crear el arreglo de restricciones
    for (int i = 0; i < leftRestNum; i++) {
        leftRestrictionsId[i] = 0;
    }

    // leer las restricciones del lado izquierdo
    for (int i = 0; i < leftRestNum; i++) {
        getline(*input, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        int a;
        while (ss >> a) { // mientras no termine esta linea
            leftRestrictionsId[i] += pow(2, N - a);
        }
    }
    
    
    // leer las restricciones del lado derecho
    getline(*input, line);
    ss.clear(); // limpiar el stream de caracteres
    ss << line; // copiar la linea al stream
    ss >> rightRestNum;
    this->nRightRestrictions = rightRestNum;
    this->rightRestrictionsId = new int[rightRestNum]; // crear la matriz de restricciones
    for (int i = 0; i < rightRestNum; i++) {
        rightRestrictionsId[i] = 0;
    }

    for (int i = 0; i < rightRestNum; i++) {
        getline(*input, line);
        ss.clear(); // limpiar el stream de caracteres
        ss << line; // copiar la linea al stream
        int a;
        while (ss >> a) { // mientras no termine esta linea
            rightRestrictionsId[i] += pow(2, N - a);
        }
    }

    // cerrar el archivo
    input->close();

    this->open = new Heap(2);
    this->closed = new Heap(2);
    this->nOperations = 0;
}

/// @brief Solve the Crossing River problem with all restrictions and elements
/// @return It does not has return but shows if problem has solution and the steps to solve it. It shows a message if the problem has not solution.
bool CrossingRiver::solve() {
    int *arr = new int[this->nTotal];
    State *actualState;
    generateOperations(arr, this->nTotal, 0);
    open->push(new State(this->nTotal));
    while (open->size != 0) {
        actualState = this->open->pop();
        this->closed->push(actualState);
        if (actualState->isFinal()) {
            cout << "SOLUTION FOUND!!" << endl;
            printSolutionPath(actualState);
            return true;
        }
        else {
            for (int i = 0; i < this->nOperations; i++) {
                if (canMoveToRight(actualState, this->operations[i])) {
                    //cout << "op" << int(i) << "verificando derecha?" << endl;
                    State *sRight = moveToRight(actualState, this->operations[i]);
                    if (sRight != nullptr) {
                        this->open->push(sRight);
                    }
                }
                if (canMoveToLeft(actualState, this->operations[i])) {
                    //cout << "op"<<int(i)<<"verificando izquierda?" << endl;
                    State *sLeft = moveToLeft(actualState, this->operations[i]);
                    if (sLeft != nullptr) {
                        this->open->push(sLeft);
                    }
                }
            }
        }
    }
    cout << "Solución NO ENCONTRADA." << endl;
    return false;
}

/// @brief Generate all valid Operations of the problem and add them to operations array
/// @param arr Binary array which represents an operation
/// @param size Lenght of arr Array
/// @param index Integer that represent the position of arr Array
void CrossingRiver::generateOperations(int *arr, int size, int index) {
    if (index == size) {
        if (validOp(arr)) {
            this->operations[this->nOperations] = new Operation(arr, size);
            this->nOperations++;
        }
        return;
    }
    arr[index] = 0;
    generateOperations(arr, size, index+1);
    arr[index] = 1;
    generateOperations(arr, size, index+1);
}

/// @brief Check if State s is in the closed Heap
/// @param s Class State
/// @return Return true if State s is in the closed Heap. Return false if is not.
bool CrossingRiver::isClosed(State *s) {
    for (int i = 0; i < this->closed->size; i++) {
        if (s->decimalLeft == this->closed->data[i]->decimalLeft) {
            return true;
        }
    }
    return false;
}

/// @brief Check if an Operation p can be applied to State s to moving elements to left side
/// @param s Class State
/// @param op Class Operation
/// @return Return true if Operation op can be applied to State s. Return false if is not possible.
bool CrossingRiver::canMoveToLeft(State *s, Operation *op) {
    for (int i = 0; i < this->nTotal; i++) {
        if (op->movement[i] == 1 && s->right[i] == 0) {
            return false;
        }
    }
    return true;
}

/// @brief Check if an Operation p can be applied to State s to moving elements to right side
/// @param s Class State
/// @param op Class Operation
/// @return Return true if Operation op can be applied to State s. Return false if not possible.
bool CrossingRiver::canMoveToRight(State *s, Operation *op) {
    for (int i = 0; i < this->nTotal; i++) {
        if (op->movement[i] == 1 && s->left[i] == 0) {
            return false;
        }
    }
    return true;
}

/// @brief Create a new State by moving elements in right array to left array
/// @param s Class State
/// @param op Class Operation
/// @return Return a Class State if new State satisfy restrictions and it is not in this->closed. Return nullptr if not.
State *CrossingRiver::moveToLeft(State *s, Operation *op) {
    int *auxLeft = new int[this->nTotal];
    int *auxRight = new int[this->nTotal];
    State *auxState;
    for (int i = 0; i < this->nTotal; i++) {
        if (s->right[i] == 1 && op->movement[i] == 1) {
            auxLeft[i] = 1;
            auxRight[i] = 0;
        }
        else {
            auxLeft[i] = s->left[i];
            auxRight[i] = s->right[i];
        }
    }
    auxState = new State(this->nTotal, auxLeft, auxRight, s);
    if ((!isClosed(auxState)) && checkRestriction(auxState)) {
        return auxState;
    }
    else {
        return nullptr;
    }
}

/// @brief Create a new State by moving elements in left array to right array
/// @param s Class State
/// @param op Class Operation
/// @return Return a Class State if new State satisfy restrictions and it is not in this->closed. Return nullptr if not.
State *CrossingRiver::moveToRight(State *s, Operation *op) {
    int *auxLeft = new int[this->nTotal];
    int *auxRight = new int[this->nTotal];
    State *auxState;
    for (int i = 0; i < this->nTotal; i++) {
        if (s->left[i] == 1 && op->movement[i] == 1) {
            auxLeft[i] = 0;
            auxRight[i] = 1;
        }
        else {
            auxLeft[i] = s->left[i];
            auxRight[i] = s->right[i];
        }
    }
    auxState = new State(this->nTotal, auxLeft, auxRight, s);
    if ((!isClosed(auxState)) && checkRestriction(auxState)) {
        return auxState;
    }
    else {
        return nullptr;
    }
}

/// @brief Check if a State satisfy problem restrictions
/// @param s Class State
/// @return true if State satisfy the problem restrictions, false if not
bool CrossingRiver::checkRestriction(State *s) {
    for (int i = 0; i < this->nLeftRestrictions; i++) {
        if (s->decimalLeft == this->leftRestrictionsId[i]) {
            return false;
        }
    }
    
    for (int i = 0; i < this->nRightRestrictions; i++) {
        if (s->decimalRight == this->rightRestrictionsId[i]) {
            return false;
        }
    }
    
    return true;
}

/// @brief Check if array operation is allowed by the problem parameters
/// @param arr Binary array with large equal to total elements of the problem (drivers + items)
/// @return Return true if array represent a valid operation, and false if not
bool CrossingRiver::validOp(int *arr) {
    int total = 0;
    int drivers = 0;

    for (int i = 0; i < this->nDrivers; i++) {
        if (arr[i] == 1) {
            drivers++;
            total++;
        }
    }

    for (int i = this->nDrivers; i < this->nTotal; i++) {
        if (arr[i] == 1) {
            total++;
        }
    }

    if (drivers >= 1 && total <= this->boatSize) {
        return true;
    }
    return false;
}

/// @brief Shows in screen the solution path of the problem
/// @param s Class State that represents the last step of the problem
void CrossingRiver::printSolutionPath(State *s) {
    int nSteps = s->getSteps();
    cout << "N° STEPS: " << nSteps - 1 << endl;
    State *aux = s;
    State *steps[nSteps];
    for (int i = 0; i < nSteps; i++) {
        steps[nSteps - i - 1] = aux;
        aux = aux->previous;
    }
    for (int j = 0; j < nSteps; j++) {
        steps[j]->print();
    }
}