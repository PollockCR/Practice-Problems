#include <iostream>

using namespace std;

int countBinaryOnes(unsigned int num);

int main(){
  unsigned int num;
  cin >> num;
  cout << countBinaryOnes(num) << endl;
  return 0;
}

int countBinaryOnes(unsigned int num){
  int count = 0;
  while(num > 0){
    if(num & 1 == 1){
      count++;
    }
    num = num >> 1;
  }
  return count;
}
