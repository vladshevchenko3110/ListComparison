#pragma once
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value);
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    int getSize() const;
    void clear();
    void pushFront(int value);
    void pushBack(int value);
    void insertAt(int index, int value);
    int getAt(int index) const;
   
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node);

        int operator*() const;
        void operator++();
        bool operator!=(const Iterator& other) const;       
        
    };

    Iterator begin() const;
    Iterator end() const;
};

