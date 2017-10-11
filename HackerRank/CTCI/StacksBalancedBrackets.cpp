// https://www.hackerrank.com/challenges/ctci-balanced-brackets
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
    stack<char> expStack;
    for(char bracket : expression){
        if(bracket == '(' || bracket == '[' || bracket == '{'){
            expStack.push(bracket);
        } else if(bracket == ')' && !expStack.empty()){
            if(expStack.top() != '('){
                return false;
            } else {
                expStack.pop();
            }
        } else if(bracket == ']' && !expStack.empty()){
            if(expStack.top() != '['){
                return false;
            } else {
                expStack.pop();
            }
        } else if(bracket == '}' && !expStack.empty()){
            if(expStack.top() != '{'){
                return false;
            } else {
                expStack.pop();
            }
        } else {
            return false;
        }
    }
    return expStack.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
