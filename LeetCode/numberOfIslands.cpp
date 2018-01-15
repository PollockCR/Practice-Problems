// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int rows;
    int cols;

    int numIslands(vector<vector<char>>& grid) {
        int i, j;
        int islands = 0;
        rows = grid.size();
        if(rows > 0){
            cols = grid[0].size();
        }
        for(i = 0; i < rows; i++){
            for(j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    foundIsland(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void foundIsland(vector<vector<char>>& grid, int i, int j){
        if(i < rows && j < cols && i >= 0 && j >= 0 && grid[i][j] == '1'){
            grid[i][j] = '0';
            foundIsland(grid, i, j+1);
            foundIsland(grid, i+1, j);
            foundIsland(grid, i-1, j);
            foundIsland(grid, i, j-1);
        }
    }
};
