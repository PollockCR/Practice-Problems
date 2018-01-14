#include <iostream>

using namespace std;

bool isLittleEndian();

int main(){
  isLittleEndian() ? cout << "Little-endian" << endl : cout << "Big-endian" << endl;
  return 0;
}

bool isLittleEndian(){
  int * myInt = new int;
  *myInt = 1;
  return (char *) myInt;
}
