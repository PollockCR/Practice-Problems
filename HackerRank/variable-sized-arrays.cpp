#include <iostream>
using namespace std;

int main() {
  int n,q,i,j,num, row, col;
  cin >> n >> q;
  int **arr = new int*[n];
  for(i=0; i < n; i++){
    cin >> num;
    int *m = new int[num];
    for(j = 0; j < num; j++){
      cin >> m[j];
    }
    *(arr+i)=m;
  }
  for(i=0; i<q; i++){
    cin >> row >> col;
    cout << arr[row][col] << endl;
  }
  return 0;
}
