#include <iostream>
#include "Operation.h"

using namespace std;

Operation::Operation() {

}

Operation::Operation(int *movement) {
    int lengthArray = sizeof(movement)/sizeof(movement[0]);
    for (int i = 0; i < lengthArray; i++) {
        this->movement[i] = movement[i];
    }
}