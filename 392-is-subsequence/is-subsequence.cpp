class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sIndex = 0;
        int tIndex = 0;

        if(t.size()== 0 && s.size()==0){
            return true;
        }

        while(tIndex < t.size()){
            if(s[sIndex] == t[tIndex]){
                sIndex++;
            }
            if(sIndex == s.size()){
                return true;
            }
            tIndex++;
        }
        return false;
    }
};