// Stack using Queues

#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int>q1;
    queue<int>q2;

    public:

    void push(int x){
        q1.push(x);
    }

    void pop(){
        if(q1.empty())
        return;

        while(q1.size() > 1){
            int a = q1.front();
            q1.pop();
            q2.push(a);
        }

        q1.pop();

        swap(q1, q2);
    };

    int top(){
        if(q1.empty()) 
        return -1;

        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q1.pop();

        q2.push(res);

        swap(q1, q2);
        return res;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30
    st.pop();
    cout << st.top() << endl; // 20
    st.pop();
    cout << st.top() << endl; // 10
}