// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i;
        if(nums.size() > 1){
            if(nums[0] > nums[1]){
                return 0;
            }
        } else {
            return 0;
        }
        for(i = 1; i < nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                return i;
            }
        }
        if(nums[i] > nums[i-1]){
            return i;
        }
    }
};
