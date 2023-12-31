﻿#include <iostream>
#include <ctime>
#include <chrono>
#include "LinkedList.h"
#include "ArrayList.h"
using namespace std;
const int N = 100000;
const int M = 1000;

class Timer {
private:
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, std::ratio<1> >;
    chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now()) {}
    void reset() { m_beg = clock_t::now(); }
    double elapsed() const {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
void FillLists(ArrayList& arraylist, LinkedList& linklist) {
    Timer t1;
    for (int i = 0; i < N; ++i)
    {
        arraylist.add(rand() % N);
    }
    cout << "ArrayList : " << t1.elapsed() << " sec" << '\n';
    Timer t2;
    for (int i = 0; i < N; ++i)
    {
        linklist.pushBack(rand() % N);
    }
    cout << "LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;

}

void BeginLists(ArrayList& arraylist, LinkedList& linklist) {
    Timer t1;
    for (int i = 0; i < M; ++i)
    {
        arraylist.insertAt(0, rand() % N);
    }
    cout << "ArrayList : " << t1.elapsed() << " sec" << '\n';
    Timer t2;
    for (int i = 0; i < M; ++i)
    {
        linklist.pushFront(rand() % N);
    }
    cout << "LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;
    

}

void EndLists(ArrayList& arraylist, LinkedList& linklist) {
    Timer t1;
    for (int i = 0; i < M; ++i)
    {
        arraylist.add(rand() % N);
    }
    cout << "ArrayList : " << t1.elapsed() << " sec" << '\n';
    Timer t2;
    for (int i = 0; i < M; ++i)
    {
        linklist.pushBack(rand() % N);
    }
    cout << "LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;

}

void MiddleLists(ArrayList& arraylist, LinkedList& linklist) {
    Timer t1;
    for (int i = 0; i < M; ++i)
    {
        arraylist.insertAt(N / 2, rand() % N);
    }
    cout << "ArrayList : " << t1.elapsed() << " sec" << '\n';
    Timer t2;
    for (int i = 0; i < M; ++i)
    {
        linklist.insertAt(N / 2, rand() % N);
    }
    cout << "LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;
}

void IndexLists(ArrayList& arraylist, LinkedList& linklist) {
    Timer t1;
    cout << "Elemend #" << 1 << ": " << arraylist.get(0) << endl;
    cout << "Index in ArrayList : " << t1.elapsed() << " sec" << '\n';
    Timer t4;
    cout << "Elemend #" << 1 << ": " << linklist.getAt(0) << endl;
    cout << "Index in LinkedList : " << t4.elapsed() << " sec" << endl << endl;

    Timer t2;
    cout << "Elemend #" << arraylist.getSize() / 2 << ": " << arraylist.get(arraylist.getSize() / 2 - 1) << endl;
    cout << "Index in ArrayList : " << t2.elapsed() << " sec" << '\n';
    Timer t5;
    cout << "Elemend #" << linklist.getSize() / 2 << ": " << linklist.getAt(linklist.getSize() / 2 - 1) << endl;
    cout << "Index in LinkedList : " << t5.elapsed() << " sec" << endl << endl;

    Timer t3;
    cout << "Elemend #" << arraylist.getSize() << ": " << arraylist.get(arraylist.getSize() - 1) << endl;
    cout << "Index in ArrayList : " << t3.elapsed() << " sec" << '\n';
    Timer t6;
    cout << "Elemend #" << linklist.getSize() << ": " << linklist.getAt(linklist.getSize() - 1) << endl;
    cout << "Index in LinkedList : " << t6.elapsed() << " sec" << endl << endl;
    cout << endl;
}

void IteratorLists(ArrayList& arraylist, LinkedList& linklist) {
    int count1 = 0;
    Timer t1;
    for (ArrayList::Iterator it = arraylist.begin(); it != arraylist.end(); ++it) {
        count1++;
        if (count1 == arraylist.getSize() / 2) {
            cout << "Elemend #" << arraylist.getSize() / 2 << ": " << *it << endl;
        }
    }
    cout << "Iterator in ArrayList : " << t1.elapsed() << " sec" << '\n';


    int count2 = 0;
    Timer t2;
    for (LinkedList::Iterator it = linklist.begin(); it != linklist.end(); ++it) {
        count2++;
        if (count2 == linklist.getSize() / 2) {
            cout << "Elemend #" << arraylist.getSize() / 2 << ": " << *it << endl;
        }
    }
    cout << "Iterator in LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    LinkedList linkedlist;
    ArrayList arraylist;

    cout << "===== Filling list =====" << endl;
    FillLists(arraylist, linkedlist);

    cout << "===== Inserting at the begin list =====" << endl;
    BeginLists(arraylist, linkedlist);

    cout << "===== Inserting at the end list =====" << endl;
    EndLists(arraylist, linkedlist);

    cout << "===== Inserting at the middle list =====" << endl;
    MiddleLists(arraylist, linkedlist);

    cout << "===== Index access =====" << endl;
    IndexLists(arraylist, linkedlist);

    cout << "===== Iterator access =====" << endl;
    IteratorLists(arraylist, linkedlist);
}

