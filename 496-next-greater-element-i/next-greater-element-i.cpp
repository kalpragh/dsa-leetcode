class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>numsindex;
        for(int i=0;i<nums1.size();i++){
            numsindex[nums1[i]]=i;
        }
        vector<int>res (nums1.size(),-1);
        stack<int>stack;
        for(int i:nums2){
            while(!stack.empty()&& i>stack.top()){
                int val=stack.top();
                stack.pop();
                int index=numsindex[val];
                res[index]=i;
            }
            if(numsindex.find(i)!=numsindex.end()){
                stack.push(i);
            }
        }
        return res;
    }
};