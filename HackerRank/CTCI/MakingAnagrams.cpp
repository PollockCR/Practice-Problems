// https://www.hackerrank.com/challenges/ctci-making-anagrams

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

map<char, int> countLetters(string s){
    map<char, int> letters;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(char letter : alphabet){
        letters[letter] = 0;
    }
    for(char letter : s){
        letters[letter]++;
    }
    return letters;
}

int numberNeeded(string a, string b) {
    map<char, int> aCounts, bCounts;
    int totalLetters = 0;
    aCounts = countLetters(a);
    bCounts = countLetters(b);
    for(auto letter : aCounts){
        totalLetters += abs(letter.second - bCounts[letter.first]);
    }
   return totalLetters;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << numberNeeded(a, b) << endl;
    return 0;
}
