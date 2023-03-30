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
    for (int i = 0; i < 1000; i++) {
        this->ops[i] = new int[4];
    }
}

void CrossingRiver::solve() {
    int *arr = new int[this->nTotal];
    int count = 0;
    generateCombinations(arr, this->nTotal, 0);
}

void CrossingRiver::generateCombinations(int *arr, int size, int index) {
    if (index == size) {
        if (validOp(arr)) {
            for (int i = 0; i < size; i++) {
                this->ops[this->nOperations][i] = arr[i];
            }
            this->nOperations++;
        }
        return;
    }
    arr[index] = 0;
    generateCombinations(arr, size, index+1);
    arr[index] = 1;
    generateCombinations(arr, size, index+1);
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