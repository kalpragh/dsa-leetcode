class KthLargest {
private:
    priority_queue<int, vector<int>,greater<int>>minhp;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            minhp.push(num);
            if(minhp.size()>k){
                minhp.pop();
            }
        }
    }
    
    int add(int val) {
        minhp.push(val);
        if(minhp.size()>k){
            minhp.pop();
        }
        return minhp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */