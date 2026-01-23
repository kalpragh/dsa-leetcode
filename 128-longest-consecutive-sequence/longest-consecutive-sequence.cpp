class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numset;
        for(int num:nums){
            numset.insert(num);
        }
        int streak=0;
        for(int num:numset){
            if(numset.find(num-1)==numset.end()){
                int length=1;
                while(numset.find(num+length)!=numset.end()){
                    length++;
                }
                streak=max(streak,length);
            }
        }
        return streak;
    }
};