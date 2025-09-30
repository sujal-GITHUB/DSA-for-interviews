// Queue using qacks

#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s1;
    stack<int>s2;

    public:

    void push(int x){
        s1.push(x);
    }

    void pop(){
        if(s1.empty())
        return;

        while(s1.size() > 1){
            int a = s1.top();
            s1.pop();
            s2.push(a);
        }

        s1.pop();

        swap(s1, s2);
    };

    int top(){
        if(s1.empty()) 
        return -1;

        while(s1.size() > 1){
            s2.push(s1.top());
            s1.pop();
        }

        int res = s1.top();
        s1.pop();

        s2.push(res);

        swap(s1, s2);
        return res;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.top() << endl; // 30
    q.pop();
    cout << q.top() << endl; // 20
    q.pop();
    cout << q.top() << endl; // 10
}