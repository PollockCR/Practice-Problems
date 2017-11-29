// https://leetcode.com/contest/weekly-contest-59/problems/self-dividing-numbers/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int i, num;
        vector<int> selfDivNums;
        for(i = left; i <= right; i++){
            for(num = i; num > 0; num /= 10){
                if((num % 10) == 0 || i % (num % 10) != 0){
                    break;
                }
            }
            if(num == 0){
                selfDivNums.push_back(i);
            }
        }
        return selfDivNums;
    }
};
