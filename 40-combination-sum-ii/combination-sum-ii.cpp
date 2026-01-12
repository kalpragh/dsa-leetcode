class Solution {
public:
    vector<vector<int>>res;
    void backtrack(int i,vector<int>&candidates,vector<int>&cur,int total,int target){
        if(total==target){
            res.push_back(cur);
            return;
        }
        if(total>target || i==candidates.size()){
            return;
        }
        cur.push_back(candidates[i]);
        backtrack(i+1,candidates,cur,total+candidates[i],target);
        cur.pop_back();

        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        backtrack(i+1,candidates,cur,total,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(),candidates.end());
        vector<int>cur;
        backtrack(0,candidates,cur,0,target);
        return res;
    }
};