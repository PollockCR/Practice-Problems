// https://www.hackerrank.com/challenges/grading

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int numGrades;
  int nextMultiple, remainder;
  cin >> numGrades;
  vector<int> grades(numGrades);
  vector<int> finalGrades(numGrades);
  for(int i = 0; i < numGrades; i++){
    cin >> grades[i];
  }
  for(int i = 0; i < numGrades; i++){
    if(grades[i] < 38){
      finalGrades[i] = grades[i];
    } else {
      nextMultiple = (ceil(double(grades[i])/5))*5;
      remainder = nextMultiple % grades[i];
      if(remainder < 3){
        finalGrades[i] = nextMultiple;
      } else {
        finalGrades[i] = grades[i];
      }
    }
    cout << finalGrades[i] << endl;
  }
  return 0;
}
