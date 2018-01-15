// https://leetcode.com/problems/number-of-corner-rectangles/

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rectangles = 0;
        for(int row = 0; row < grid.size()-1; row++){
            for(int col = 0; col < grid[row].size()-1; col++){
                if(grid[row][col] == 1){
                    for(int right = col+1; right < grid[row].size(); right++){
                        for(int bottom = row+1; bottom < grid.size(); bottom++){
                            if(grid[row][right] == 1 && grid[bottom][col] == 1 && grid[bottom][right] == 1){
                                rectangles++;
                            }
                        }
                    }
                }
            }
        }
        return rectangles;
    }
};
