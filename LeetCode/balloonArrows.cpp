// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
// SOLUTION INCOMPLETE

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int i, j;
        unordered_map<int, vector<int>> balloonsHit;
        for(i = 0; i < points.size(); i++){
            for(j = get<0>(points[i]); j <= get<1>(points[i]); j++){
                vector<int> temp(1,i);
                auto res = balloonsHit.emplace(j, temp);
                if(!res.second){
                    res.first->second.push_back(i);
                }
            }
        }
        for(auto& point: balloonsHit){
            cout << point.first << ": ";
            for(int house: point.second){
                cout << house << ' ';
            }
            cout << endl;
        }
        return 0;
    }
};
