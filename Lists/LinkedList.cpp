#include "LinkedList.h"

Node::Node(int value) {
    data = value;
    prev = nullptr;
    next = nullptr; 
} 

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}  

LinkedList::~LinkedList() {
    clear();
}

int LinkedList::getSize() const {
    return size;
}

void LinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

void LinkedList::pushFront(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void LinkedList::pushBack(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::insertAt(int index, int value) {
    if (index < 0 || index > size)
        return;

    if (index == 0) {
        pushFront(value);
        return;
    }

    if (index == size) {
        pushBack(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

int LinkedList::getAt(int index) const {
    if (index < 0 || index >= size)
        return -1;

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}


LinkedList::Iterator::Iterator(Node* node) {
    current = node; 
} 

int LinkedList::Iterator::operator*() const {
    return current->data;
}

void LinkedList::Iterator::operator++() {
    current = current->next;
}

bool LinkedList::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}


LinkedList::Iterator LinkedList::begin() const {
    return Iterator(head);
}

LinkedList::Iterator LinkedList::end() const {
    return Iterator(nullptr);
}