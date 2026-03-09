class Solution {
public:
    int solve(string &s,int i,long long res,int sign){
        if(i>=s.length() || !isdigit(s[i])){
            return (int)(res*sign);
        }
        int num=s[i]-'0';
        res=res*10+num;
        if(sign==1 && res>INT_MAX){
            return INT_MAX;
        }
        if(sign==-1 && -res<INT_MIN){
            return INT_MIN;
        }
        return solve(s,i+1,res,sign);
    }
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){ //removing leading space
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        return solve(s,i,0,sign);
    }
};