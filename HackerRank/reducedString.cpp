// https://www.hackerrank.com/challenges/reduced-string/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reducedString(string s){
  bool sWasChanged;
  do {
    sWasChanged = false;
    if(s == ""){
      return "Empty String";
    }
    for(int i = 0; i < s.length()-1; i++){
      if(s[i] == s[i+1]){
        s.erase(i,2);
        sWasChanged = true;
        break;
      }
    }
  } while(sWasChanged);
  return s;
}

int main() {
  string s;
  cin >> s;
  cout << reducedString(s);
  return 0;
}
