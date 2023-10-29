#include <iostream>
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
    cout << "Elemend #" << N / 2 << ": " << arraylist.get(N / 2) << endl;
    cout << "Index in ArrayList : " << t1.elapsed() << " sec" << '\n';

    Timer t2;
    cout << "Elemend #" << N / 2 << ": " << linklist.getAt(N / 2) << endl;
    cout << "Index in LinkedList : " << t2.elapsed() << " sec" << '\n';
    cout << endl;
}

void IteratorLists(ArrayList& arraylist, LinkedList& linklist) {
    int count1 = -1;
    Timer t1;
    for (ArrayList::Iterator it = arraylist.begin(); it != arraylist.end(); ++it) {
        count1++;
        if (count1 == N / 2) {
            cout << "Elemend #" << N / 2 << ": " << *it << endl;
        }
    }
    cout << "Iterator in ArrayList : " << t1.elapsed() << " sec" << '\n';

    int count2 = -1;
    Timer t2;
    for (LinkedList::Iterator it = linklist.begin(); it != linklist.end(); ++it) {
        count2++;
        if (count2 == N / 2) {
            cout << "Elemend #" << N/2 << ": " << *it << endl;
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

