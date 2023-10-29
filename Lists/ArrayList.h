#pragma once
class ArrayList {
private:
    int* data;      
    int size;       
    int capacity;   

public:
    ArrayList(int initialCapacity = 10);
    ~ArrayList();

    void add(int value);
    int get(int index);
    void insertAt(int index, int value);
    int getSize();

    class Iterator {
    private:
        int* ptr;

    public:
        Iterator(int* p);
        int operator*();
        Iterator& operator++();
        bool operator!=(const Iterator& other);
    };

    Iterator begin();
    Iterator end();
};

