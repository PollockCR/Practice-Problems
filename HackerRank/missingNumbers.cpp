// https://www.hackerrank.com/challenges/missing-numbers/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main() {
  int aSize, bSize, tempInt;
  map<int, int> a;
  map<int, int> b;
  map<int, int>::iterator it;
  cin >> aSize;
  for(int i = 0; i < aSize; i++){
    cin >> tempInt;
    it = a.find(tempInt);
    if(it != a.end()){
      it->second++;
    } else {
      a.emplace_hint(it, tempInt, 1);
    }
  }
  cin >> bSize;
  for(int i = 0; i < bSize; i++){
    cin >> tempInt;
    it = a.find(tempInt);
    if(it != a.end()){
      it->second--;
      if(it->second == 0){
        a.erase(it);
      }
    } else {
      it = b.find(tempInt);
      if(it != b.end()){
        it->second++;
      } else {
        b.emplace_hint(it, tempInt, 1);
      }
    }
  }
  for(auto& x: b){
    cout << x.first << ' ';
  }  return 0;
}
