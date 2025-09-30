#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int top() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.top() << endl; // 10
    q.pop();
    cout << q.top() << endl; // 20
    q.pop();
    cout << q.top() << endl; // 30
}
