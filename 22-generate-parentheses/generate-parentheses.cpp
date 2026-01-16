class Solution {
public:
    void backtrack(int countopen,int countclose,int n,vector<string>&res,string &stack){
        if(countopen==countclose &&countopen==n){
            res.push_back(stack);
            return;
        }
        if(countopen<n){
            stack+='(';
            backtrack(countopen+1,countclose,n,res,stack);
            stack.pop_back();
        }
        if(countclose<countopen){
            stack+=')';
            backtrack(countopen,countclose+1,n,res,stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
};