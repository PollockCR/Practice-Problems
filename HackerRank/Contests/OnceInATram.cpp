// https://www.hackerrank.com/contests/w34/challenges/once-in-a-tram
// Given a 6 digit number, prints next 6 digit number where first 3 digits equal last 3 digits

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void checkOverflow(vector<int>& digits, int index){
  if(digits[index] == 10 && index != 0){
    digits[index] = 0;
    digits[index - 1]++;
    checkOverflow(digits, index - 1);
  }
}

bool isLucky(vector<int>& digits){
  return(digits[0]+digits[1]+digits[2] == digits[3]+digits[4]+digits[5]);
}

vector<int> nextLucky(vector<int> digits){
  do{
    digits[5]++;
    checkOverflow(digits, 5);
  } while(!isLucky(digits));
  return digits;
}

int main() {
  vector<int> digits(6);
  vector<int> luckyDigits(6);
  long num;
  cin >> num;
  for(int i = 5; i >= 0; i--){
    digits[i] = num % 10;
    num = num / 10;
  }
  luckyDigits = nextLucky(digits);
  for(int i = 0; i < 6; i++){
    cout << luckyDigits[i];
  }
  return 0;
}
