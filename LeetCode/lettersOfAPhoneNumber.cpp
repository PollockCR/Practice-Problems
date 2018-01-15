// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combos;
        if(!digits.empty()){
            combos.emplace_back("");
        }
        for(char digit : digits){
            combos = addDigit(combos, digit);
        }
        return combos;
    }

    vector<string> addDigit(vector<string> oldCombos, char digit){
        vector<string> newCombos;
        for(string combo : oldCombos){
            switch(digit){
                case '2':
                    newCombos.emplace_back(combo + 'a');
                    newCombos.emplace_back(combo + 'b');
                    newCombos.emplace_back(combo + 'c');
                    break;
                case '3':
                    newCombos.emplace_back(combo + 'd');
                    newCombos.emplace_back(combo + 'e');
                    newCombos.emplace_back(combo + 'f');
                    break;
                case '4':
                    newCombos.emplace_back(combo + 'g');
                    newCombos.emplace_back(combo + 'h');
                    newCombos.emplace_back(combo + 'i');
                    break;
                case '5':
                    newCombos.emplace_back(combo + 'j');
                    newCombos.emplace_back(combo + 'k');
                    newCombos.emplace_back(combo + 'l');
                    break;
                case '6':
                    newCombos.emplace_back(combo + 'm');
                    newCombos.emplace_back(combo + 'n');
                    newCombos.emplace_back(combo + 'o');
                    break;
                case '7':
                    newCombos.emplace_back(combo + 'p');
                    newCombos.emplace_back(combo + 'q');
                    newCombos.emplace_back(combo + 'r');
                    newCombos.emplace_back(combo + 's');
                    break;
                case '8':
                    newCombos.emplace_back(combo + 't');
                    newCombos.emplace_back(combo + 'u');
                    newCombos.emplace_back(combo + 'v');
                    break;
                case '9':
                    newCombos.emplace_back(combo + 'w');
                    newCombos.emplace_back(combo + 'x');
                    newCombos.emplace_back(combo + 'y');
                    newCombos.emplace_back(combo + 'z');
                    break;
                case '0':
                    newCombos.emplace_back(combo + ' ');
                default:
                    return oldCombos;
            }
        }
        return newCombos;
    }
};
