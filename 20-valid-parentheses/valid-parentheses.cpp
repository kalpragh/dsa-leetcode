class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char>closetoopen={
            {')','('},
            {']','['},
            {'}','{'}
        };
        std::stack<char>stack;
        for(char ch:s){
            if(closetoopen.count(ch)){
                if(!stack.empty() && stack.top()==closetoopen[ch]){
                    stack.pop();
                }else{
                    return false;
                }
            } else {
                stack.push(ch);
            }
        }
        return stack.empty();
    }
};