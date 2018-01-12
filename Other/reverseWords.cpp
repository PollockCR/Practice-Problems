#include <iostream>

using namespace std;

string reverseWords(string s);

int main(){
  string s;
  getline(cin, s);
  cout << reverseWords(s) << endl;
  return 0;
}

string reverseWords(string s){
  int i, j;
  string revS = "";
  // iterate from end of string
  for(i = s.length() - 1; i > 0; i--){
    if(s[i] == ' '){
      for(j = i+1; j < s.length() && s[j] != ' '; j++){
        revS += s[j];
      }
      revS += s[i];
    }
  }
  // at beginning of string
  for(j = 0; j < s.length() && s[j] != ' '; j++){
    revS += s[j];
  }
  return revS;
}
