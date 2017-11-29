// https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string sBuffer;
        uint32_t solution;
        sBuffer = bitset<32>(n).to_string();
        reverse(sBuffer.begin(), sBuffer.end());
        sBuffer.resize(32, '0');
        solution = stol(sBuffer, nullptr, 2);
        return solution;
    }
};
