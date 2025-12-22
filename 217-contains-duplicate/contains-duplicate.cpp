class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>dups;
        for(int num:nums){
            if(dups.count(num)){
                return true;
            }
            dups.insert(num);
        }
        return false;
    }
};