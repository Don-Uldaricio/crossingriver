#include <iostream>

using namespace std;

class State {
    public:
        int value;
        int nElem;
        int *left; // elementos a la izquierda
        int *right; // elementos a la derecha
        int boatSide; // lado donde se encuentra el bote. 0: izquierda 1: derecha
        State* previous;
        State(int nElem); // constructor por fecto sin argumentos
        State(int nElem, int *left, int *right, State* previous); // constructores especificos
        ~State(); // destructor
        void setValue(int value);
        int getValue();
        void print(); // imprime el estado
        bool isFinal(); // verifica si es el estado final
        void printPath(); // imprime el camino desde el estado inicial hasta el final
};