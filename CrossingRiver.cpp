#include <iostream>
#include <cmath>
#include "CrossingRiver.h"

using namespace std;

CrossingRiver::CrossingRiver() {
    this->open = new Heap(2);
    this->closed = new Heap(2);
    Load *p = new Load("sistema.txt");
    this->nDrivers = p->getDrivers();
    this->nElem = p->getElements();
    this->nTotal = p->getTotal();
    this->boatSize = p->getBoatSize();
    this->nOperations = 0;
    this->nLeftRestrictions = p->leftRestNum;
    this->nRightRestrictions = p->rightRestNum;
    this->leftRestrictionsId = new int[this->nLeftRestrictions];
    this->rightRestrictionsId = new int[this->nRightRestrictions];

    for (int i = 0; i < this->nLeftRestrictions; i++) {
        this->leftRestrictionsId[i] = p->leftRest[i];
    }

    for (int i = 0; i < this->nRightRestrictions; i++) {
        this->rightRestrictionsId[i] = p->rightRest[i];
    }
}

bool CrossingRiver::solve() {
    int *arr = new int[this->nTotal];
    State *actualState;
    generateOperations(arr, this->nTotal, 0);
    open->push(new State(this->nTotal));
    while (open->size != 0) {
        actualState = this->open->pop();
        this->closed->push(actualState);
        if (actualState->isFinal()) {
            cout << "SOLUCIÓN ENCONTRADA!!" << endl;
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

bool CrossingRiver::isClosed(State *s) {
    for (int i = 0; i < this->closed->size; i++) {
        if (s->decimalLeft == this->closed->data[i]->decimalLeft) {
            return true;
        }
    }
    return false;
}

bool CrossingRiver::canMoveToLeft(State *s, Operation *op) {
    for (int i = 0; i < this->nTotal; i++) {
        if (op->movement[i] == 1 && s->right[i] == 0) {
            return false;
        }
    }
    return true;
}

bool CrossingRiver::canMoveToRight(State *s, Operation *op) {
    for (int i = 0; i < this->nTotal; i++) {
        if (op->movement[i] == 1 && s->left[i] == 0) {
            return false;
        }
    }
    return true;
}

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

void CrossingRiver::printSolutionPath(State *s) {
    int nSteps = s->getSteps();
    cout << "N° PASOS: " << nSteps - 1 << endl;
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