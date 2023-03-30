#include <iostream>
#include <cmath>
#include "CrossingRiver.h"

using namespace std;

CrossingRiver::CrossingRiver() {
    Load *p = new Load("sistema.txt");
    this->nDrivers = p->getDrivers();
    this->nElem = p->getElements();
    this->nTotal = p->getTotal();
    this->boatSize = p->getBoatSize();
    this->nOperations = 0;
}

void CrossingRiver::solve() {
    int *arr = new int[this->nTotal];
    int count = 0;
    generateOperations(arr, this->nTotal, 0);

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