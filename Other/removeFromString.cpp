#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeFromString(string s, string r);

int main(){
  string s, r;
  cin >> s >> r;
  cout << removeFromString(s, r) << endl;
  return 0;
}

string removeFromString(string s, string r){
  vector<bool> removeChars(128, false);
  string finalS = "";
  for(char c : r){
    removeChars[c] = true;
  }
  for(char c : s){
    if(!removeChars[c]){
      finalS += c;
    }
  }
  return finalS;
}
