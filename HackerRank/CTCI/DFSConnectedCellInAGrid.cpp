// https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem

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

int countRegion(vector<vector<int>> &grid, int xPos, int yPos){
    int count = 0;
    if(yPos >= grid.size() || yPos < 0 || xPos >= grid[yPos].size() || xPos < 0){
        return 0;
    } else if(grid[yPos][xPos] == 0 || grid[yPos][xPos] == -1){
        return 0;
    }else if(grid[yPos][xPos] == 1){
        grid[yPos][xPos] = -1;
        count++;
        count += countRegion(grid, xPos - 1, yPos - 1);
        count += countRegion(grid, xPos, yPos - 1);
        count += countRegion(grid, xPos + 1, yPos - 1);
        count += countRegion(grid, xPos - 1, yPos);
        count += countRegion(grid, xPos + 1, yPos);
        count += countRegion(grid, xPos - 1, yPos + 1);
        count += countRegion(grid, xPos, yPos + 1);
        count += countRegion(grid, xPos + 1, yPos + 1);
    }
    return count;
}

int get_biggest_region(vector< vector<int> > grid) {
    int xPos, yPos, biggestRegion = 0, regionSize;
    int ySize, xSize;
    ySize = grid.size();
    if(ySize > 0){
        xSize = grid[0].size();
    }
    for(yPos = 0; yPos < ySize; yPos++){
        for(xPos = 0; xPos < xSize; xPos++){
            if(grid[yPos][xPos] == 1){
                regionSize = countRegion(grid, xPos, yPos);
                if(regionSize > biggestRegion){
                    biggestRegion = regionSize;
                }
            }
        }
    }
    return biggestRegion;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
