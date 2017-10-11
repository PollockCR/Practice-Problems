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
#include <unordered_set>

using namespace std;

bool ransom_note(unordered_multiset<string> &magazine, vector<string> ransom) {
    unordered_multiset<string>::iterator it;
    for(string word : ransom){
        it = magazine.find(word);
        if(it == magazine.end()){
            return false;
        }
        else{
            magazine.erase(it);
        }
    }
    return true;
}

int main(){
    int m;
    int n;
    string word;
    cin >> m >> n;
    unordered_multiset<string> magazine;
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> word;
       magazine.insert(word);
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
