class MinStack {
public:
    stack<pair<int,int>>minstack;
    MinStack() {
    }
    
    void push(int val) {
        if(minstack.empty()){
            minstack.push({val,val});
        }
        else{
            int minval=min(minstack.top().second,val);
            minstack.push({val,minval});
        }
    }
    
    void pop() {
        if(!minstack.empty())minstack.pop();
    }
    
    int top() {
        return minstack.top().first;
    }
    
    int getMin() {
        return minstack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */