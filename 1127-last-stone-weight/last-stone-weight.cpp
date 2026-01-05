class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxhp;
        for(int stone:stones){
            maxhp.push(stone);
        }
        while(maxhp.size()>1){
            int first=maxhp.top();
            maxhp.pop();
            int second=maxhp.top();
            maxhp.pop();
            if(second<first){
                second=first-second;
                maxhp.push(second);
            }
        }

        maxhp.push(0);
        return maxhp.top();
    }
};