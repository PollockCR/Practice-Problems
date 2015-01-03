/* Problem found here:
https://www.hackerrank.com/challenges/pangrams

Problem Statement
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly because it is a pangram. ( pangrams are sentences constructed by using every letter of the alphabet at least once. )
After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.
Given a sentence s, tell Roy if it is a pangram or not.
Input Format
Input consists of a line containing s.
Constraints 
Length of s can be atmost 103 (1≤|s|≤103) and it may contain spaces, lowercase and uppercase letters. Lowercase and uppercase instances of a letter are considered same.
Output Format
Output a line containing pangram if s is a pangram, otherwise output not pangram.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool testPangram( string a );

int main() {
  string a;
  getline(cin,a);
  if( testPangram(a) ){
    cout << "pangram";
  } else {
    cout << "not pangram";
  }
  return 0;
}

bool testPangram( string a ){
  if( a.size() < 26 ){
    return false;
  }
  bool lettersFound[26];
  char c;
  for( int i = 0; i < 26; i++ ){
    lettersFound[i] = false;
  }
  for( int i = 0; i < a.size(); i++ ){
    c = a[i];
    if( isalpha( c )){
      lettersFound[ tolower(c) - 'a' ] = true;
    }
  }
  for( int i = 0; i < 26; i++ ){
    if( lettersFound[i] == false ){
      return false;
    }    
  }
  return true;
}
