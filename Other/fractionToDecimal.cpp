#include <string>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

string fractionToDecimal(int numerator, int denominator);

int main(){
  int numerator, denominator;
  cin >> numerator >> denominator;
  cout << fractionToDecimal(numerator, denominator);
  return 0;
}

string fractionToDecimal(int numerator, int denominator) {
    map<long, string> remMap;
    string soln = "";
    long num = numerator, rem, iter = 0, repIndex;
    double tempAnswer = (double)numerator / (double)denominator;
    if(tempAnswer < 0){
        soln += '-';
    }
    do{
        if(iter == 1){
            soln += ".";
        }
        soln += to_string(abs(num / denominator));
        rem = num % denominator;
        remMap.emplace(num, soln);
        num = rem * 10;
        iter++;
    }while(rem != 0 && remMap.find(num) == remMap.end());
    if(remMap.find(num) != remMap.end() && num != 0){
        repIndex = soln.find(remMap[num]);
        soln.insert(repIndex+remMap[num].length()-1, "(");
        soln += ")";
    }
    return soln;
}
