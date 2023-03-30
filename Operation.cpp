#include <iostream>
#include "Operation.h"

using namespace std;

Operation::Operation() {

}

Operation::Operation(int *m, int size) {
    this->movement = new int[size];
    for (int i = 0; i < size; i++) {
        this->movement[i] = m[i];
    }
}