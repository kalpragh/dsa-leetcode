class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>stack; //stores indices
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<2*n;i++){
            int curr=nums[i%n];
            while(!stack.empty() && nums[stack.top()]<curr){
                res[stack.top()]=curr;
                stack.pop();
            }
            if(i<nums.size()){
                stack.push(i);
            }
        }
        return res;
    }
};