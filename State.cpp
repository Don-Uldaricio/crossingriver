#include "State.h"

/// @brief Constructor of State Class that initializes the attributes
/// @param nElem Integer that represent the total number of elements in the problem
State::State(int nElem) {
    this->distance = 0;
    this->decimalLeft = 0;
    this->decimalRight = 0;
    this->nElem = nElem;
    this->left = (int*) malloc(sizeof(int)*nElem);
    this->right = (int*) malloc(sizeof(int)*nElem);
    for (int i = 0; i < nElem; i++) {
        left[i] = 1; // todos a la izquierda
        right[i] = 0; // nada a la derecha
        this->distance = this->distance + left[i];
        this->decimalLeft += left[i] * pow(2, this->nElem - 1 - i);
        this->decimalRight += right[i] * pow(2, this->nElem - 1 - i);
    }
    this->boatSide = 0;
    this->previous = nullptr;
}

/// @brief Constructor of State Class that initializes the attributes
/// @param nElem Integer that represents the total number of elements in the problem
/// @param left Binary Array that represents the elements on the left
/// @param right Binary Array that represents the elements on the right
/// @param previous Class State that represents the previous State
State::State(int nElem, int *left, int *right, State* previous) {
    this->distance = 0;
    this->decimalLeft = 0;
    this->decimalRight = 0;
    this->nElem = nElem;
    this->left = (int*) malloc(sizeof(int)*nElem);
    this->right = (int*) malloc(sizeof(int)*nElem);
    for (int i = 0; i < nElem; i++) {
        this->left[i] = left[i];
        this->right[i] = right[i];
        this->distance += left[i];
        decimalLeft += left[i] * pow(2, this->nElem - 1 - i);
        decimalRight += right[i] * pow(2, this->nElem - 1 - i);
    }
    this->boatSide = 0;
    this->previous = previous;
}

/// @brief Get the distance value of the State Class
/// @return Integer that represents the estimate distance (heuristic) of the State
int State::getDistance() {
    return this->distance;
}

/// @brief Get the decimal representation of left binary array
/// @return Integer
int State::getDecimalLeft() {
    return this->decimalLeft;
}

/// @brief Get the decimal representation of right binary array
/// @return Integer
int State::getDecimalRight() {
    return this->decimalRight;
}

/// @brief Shows the State representation on the screen
void State::print() {
    for (int i = 0; i < this->nElem; i++) {
        cout << this->left[i] << " ";
    }
    cout << " | " ;
    for (int i = 0; i < this->nElem; i++) {
        cout << right[i] << " ";
    }
    cout << endl;
}

/// @brief Check is State is final state, which means all elements on the left array are 0
/// @return Return true if the State is final state. Return false if is not.
bool State::isFinal() {
    for (int i = 0; i < this->nElem; i++) {
        if (this->right[i] == 0) {
            return false;
        }
    }
    return true;
}

/// @brief Shows the path of actual State in the screen
void State::printPath() {
    State *actual = this; // this es puntero al objeto actual
    actual->print();
    while (actual->previous != nullptr) {
        actual = actual->previous;
        actual->print();
    }
}

/// @brief Calculate the number of steps to the actual State, which means, the amount of previous states of the actual State
/// @return Integer that represents the amount of steps to the actual state
int State::getSteps() {
    int steps = 0;
    State *aux = this;
    while (aux != nullptr) {
        aux = aux->previous;
        steps++;
    }
    return steps;
}