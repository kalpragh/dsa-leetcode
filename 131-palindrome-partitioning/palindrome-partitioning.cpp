class Solution {
public:
    bool ispalindrome(string x,int l,int r){
        while(l<r){
            if(x[l]!=x[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(int i,vector<string>&part,vector<vector<string>>&res,string &s){
        if(i>=s.length()){
            res.push_back(part);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(ispalindrome(s,i,j)){
                part.push_back(s.substr(i,j-i+1));
                dfs(j+1,part,res,s);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>part;
        vector<vector<string>>res;
        dfs(0,part,res,s);
        return res;
    }
};