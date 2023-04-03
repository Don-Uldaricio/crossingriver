#include <iostream>
#include "Operation.h"

using namespace std;

/// @brief Constructor of Operation Class
/// @param m Binary array that represents the elements that will be moved
/// @param size Integer that represent the lenght of the m Array
Operation::Operation(int *m, int size) {
    this->movement = new int[size];
    for (int i = 0; i < size; i++) {
        this->movement[i] = m[i];
    }
}