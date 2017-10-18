// https://www.hackerrank.com/challenges/ctci-comparator-sorting

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
  string name;
  int score;
};

vector<Player> comparator(vector<Player> players) {
  int swaps;
  for(int i = 0; i < players.size(); i++){
    swaps = 0;
    for(int j = 0; j < players.size()-1; j++){
      if(players[j].score < players[j+1].score){
        swap(players[j],players[j+1]);
        swaps++;
      }
    }
    if(swaps == 0){
      break;
    }
  }
  for(int i = 0; i < players.size(); i++){
    for(int j = 0; j < players.size()-1; j++){
      if(players[j].score == players[j+1].score){
        if(players[j].name > players[j+1].name){
          swap(players[j], players[j+1]);
        }
      }
    }
  }
  return players;
}

int main() {

  int n;
  cin >> n;
  vector< Player > players;
  string name;
  int score;
  for(int i = 0; i < n; i++){
    cin >> name >> score;
    Player p1;
    p1.name = name, p1.score = score;
    players.push_back(p1);
  }

  vector<Player > answer = comparator(players);
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i].name << " " << answer[i].score << endl;
  }
  return 0;
}
