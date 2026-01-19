class Solution {
public:
    vector<string>digtochar={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    void backtrack(int i,string &digits,string curstr){
        if(curstr.size()==digits.size()){
            res.push_back(curstr);
            return;
        }
        string letters=digtochar[digits[i]-'0'];
        for(char c: letters){
            backtrack(i+1,digits,curstr+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return res;
        backtrack(0,digits,"");
        return res;
    }
};