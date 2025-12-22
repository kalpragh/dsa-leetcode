class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numstarget;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            if(numstarget.find(diff)!=numstarget.end()){
                return{numstarget[diff],i};
            }
            numstarget.insert({nums[i],i});
        }
        return {};

    }
};