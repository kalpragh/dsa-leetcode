class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>stringS;
        unordered_map<char,int>stringT;
        for(char ch:s){
            stringS[ch]++;
        }
        for(char x:t){
            stringT[x]++;
        }
        return stringS==stringT;
    }
};