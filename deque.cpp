#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(0);
    cout << "Deque: ";
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    d.pop_front();
    cout << "After pop_front, Deque: ";
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;

    d.pop_back();
    cout << "After pop_back, Deque: ";
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Element at index 2: " << d[2] << endl;
    return 0;
}