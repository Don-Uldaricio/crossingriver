#include "Heap.h"

/// @brief Create a Heap with capacity
/// @param capacity Integer that represents the capacity of the Heap
Heap::Heap(int capacity) {
    this->capacity = capacity;
    this->data = new State*[capacity];
    size = 0;
}

/// @brief Destructor of Heap Class
Heap::~Heap() {
    delete[] data;
}

/// @brief Swap the i element with the j element
/// @param i Integer that represents the index of element i in the Heap
/// @param j Integer that represents the index of element j in the Heap
void Heap::swap(int i, int j) {
    State *temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

/// @brief Get the left child of element i in the Heap
/// @param i Integer that represent the index of element
/// @return Return integer of the left child of the i element
int Heap::left_idx(int i) {
    return 2*i + 1;
}

/// @brief Get the right child of element i in the Heap
/// @param i Integer that represent the index of element
/// @return Return integer of the right child of the i element
int Heap::right_idx(int i) {
    return 2*i + 2;
}

/// @brief Get the integer value of the parent of i element
/// @param i Integer that represents the index of element
/// @return Returns the integer of the parent of i element
int Heap::parent_idx(int i) {
    return (i-1)/2;
}

/// @brief Get the first element of Heap
/// @return Class State
State* Heap::pop() {
    if (size == 0) {
        return nullptr;
    }
    State *s = data[0];
    data[0] = data[size-1];
    size--;
    heapify(0);
    return s;
}

/// @brief Add State s to Heap by distance value of the State s
/// @param s Class State
void Heap::push(State *s) {
    if (size == capacity) {
        State **temp= new State*[capacity*2];
        for(int i=0; i<size; i++){
            temp[i] = data[i]; 
        }
        delete[] data;
        data = temp;
        capacity = capacity*2;
    }
    data[size] = s;
    size++;
    int i = size-1;
    while (i > 0) {
        int p = parent_idx(i);
        if (data[i]->distance < data[p]->distance) {
            swap(i, p);
            i = p;
        } else {
            break;
        }
    }
}

/// @brief Order the Heap after pop an element
/// @param i Integer that represents the index of element
void Heap::heapify(int i) {
    int l = left_idx(i);
    int r = right_idx(i);
    int smallest = i;
    if (l < size && data[l]->distance < data[i]->distance) {
        smallest = l;
    }
    if (r < size && data[r]->distance < data[smallest]->distance) {
        smallest = r;
    }
    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}