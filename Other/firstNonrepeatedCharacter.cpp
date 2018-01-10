#include <iostream>
#include <map>
#include <string>

using namespace std;

char firstNonrepeatedCharacter(string s);

int main(){
  string s;
  char nonrepChar;
  getline(cin, s);
  nonrepChar = firstNonrepeatedCharacter(s);
  if(nonrepChar){
    cout << nonrepChar << endl;
  }
  return 0;
}

char firstNonrepeatedCharacter(string s){
  map<char, int> charMap;
  for(char c: s){
    auto insertPair = charMap.emplace(c, 1);
    if(insertPair.second == false){
      insertPair.first->second++;
    }
  }
  for(char c: s){
    if(charMap[c] == 1){
      return c;
    }
  }
  return '\0';
}
