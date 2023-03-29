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
    int arr[this->nTotal];
    int count = 0;
    generateCombinations(arr, this->nTotal, 0, count);
}

void CrossingRiver::generateCombinations(int arr[], int size, int index, int& count) {
    if (index == size) {
        for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        if (validOp(arr)) {
            operations[nOperations] = new Operation(arr);
            this->nOperations++;
            cout << "n ops:" << this->nOperations << endl;
        }
        count++;
        return;
    }
    arr[index] = 0;
    generateCombinations(arr, size, index+1, count);
    arr[index] = 1;
    generateCombinations(arr, size, index+1, count);
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