#include "State.h"

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
        this->distance = this->distance + left[i];
        decimalLeft += left[i] * pow(2, this->nElem - 1 - i);
        decimalRight += right[i] * pow(2, this->nElem - 1 - i);
    }
    this->boatSide = 0;
    this->previous = previous;
}

State::~State() {
    // no se necesita
}

void State::setDistance(int distance) {
    this->distance = distance;
}

int State::getDistance() {
    return this->distance;
}

int State::getDecimalLeft() {
    return this->decimalLeft;
}

int State::getDecimalRight() {
    return this->decimalRight;
}

void State::print() {
    cout << "Izquierda: ";
    for (int i = 0; i < this->nElem; i++) {
        cout << this->left[i] << " ";
    }
    cout << endl;
    cout << "Derecha: ";
    for (int i = 0; i < this->nElem; i++) {
        cout << right[i] << " ";
    }
    cout << endl;
}

// asumimos que no hay contradicciones 
bool State::isFinal() {
    for (int i = 0; i < this->nElem; i++) {
        if (this->right[i] == 0) {
            return false;
        }
    }
    return true;
}

void State::printPath() {
    State *actual = this; // this es puntero al objeto actual
    actual->print();
    while (actual->previous != nullptr) {
        actual = actual->previous;
        actual->print();
    }
}