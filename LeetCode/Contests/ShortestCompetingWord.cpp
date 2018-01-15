// https://leetcode.com/problems/shortest-completing-word/

class Solution {
public:
    static bool compareWords(string a, string b){
        return (a.size() < b.size());
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        stable_sort(words.begin(), words.end(), compareWords);
        for(string word: words){
            cout << word << ' ';
            string wordCopy = word;
            bool match = true;
            for(char letter: licensePlate){
                if(match && isalpha(letter)){
                    size_t found = wordCopy.find(tolower(letter));
                    if(found == string::npos){
                        match = false;
                    } else {
                        wordCopy.erase(found, 1);
                    }
                }
            }
            if(match){
                return word;
            }
        }
    }
};
