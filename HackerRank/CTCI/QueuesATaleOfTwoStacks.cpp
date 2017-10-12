// https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stackNewestOnTop, stackOldestOnTop;
        void push(int x) {
            stackNewestOnTop.push(x);
        }

        void pop() {
            if(stackOldestOnTop.empty()){
                while(!stackNewestOnTop.empty()){
                    stackOldestOnTop.push(stackNewestOnTop.top());
                    stackNewestOnTop.pop();
                }
            }
            stackOldestOnTop.pop();
        }

        int front() {
            if(stackOldestOnTop.empty()){
                while(!stackNewestOnTop.empty()){
                    stackOldestOnTop.push(stackNewestOnTop.top());
                    stackNewestOnTop.pop();
                }
            }
            return stackOldestOnTop.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}
