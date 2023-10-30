#include "ArrayList.h"
#include <stdexcept>

ArrayList::ArrayList(int initialCapacity) {
    capacity = initialCapacity;
    data = new int[capacity];
    size = 0;
}

ArrayList::~ArrayList() {
    delete[] data;
}

void ArrayList::add(int value) {
    if (size >= capacity) {
        
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size] = value;
    size++;
}

int ArrayList::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of bounds");
    }
    return data[index];
}

void ArrayList::insertAt(int index, int value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index is out of bounds");
    }

    if (size >= capacity) {
        
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

int ArrayList::getSize() {
    return size;
}

ArrayList::Iterator::Iterator(int* p) {
    ptr = p; 
} 

int ArrayList::Iterator::operator*() {
    return *ptr;
}

ArrayList::Iterator& ArrayList::Iterator::operator++() {
    ptr++;
    return *this;
}

bool ArrayList::Iterator::operator!=(const Iterator& other) {
    return ptr != other.ptr;
}

ArrayList::Iterator ArrayList::begin() {
    return Iterator(data);
}

ArrayList::Iterator ArrayList::end() {
    return Iterator(data + size);
}