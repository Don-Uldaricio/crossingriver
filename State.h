#include <iostream>

using namespace std;

class State {
    public:
        int distance; // Heurística del estado, es decir, qué tan lejos estamos del estado final
        int nElem; // Cantidad de elementos del problema c + e = n
        int *left; // elementos a la izquierda
        int *right; // elementos a la derecha
        int boatSide; // lado donde se encuentra el bote. 0: izquierda 1: derecha
        State* previous;
        State(int nElem); // constructor por fecto sin argumentos
        State(int nElem, int *left, int *right, State* previous); // constructores especificos
        ~State(); // destructor
        void setDistance(int distance);
        int getDistance();
        void print(); // imprime el estado
        bool isFinal(); // verifica si es el estado final
        void printPath(); // imprime el camino desde el estado inicial hasta el final
};