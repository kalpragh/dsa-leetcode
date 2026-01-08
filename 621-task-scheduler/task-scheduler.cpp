class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(char t: tasks){
            count[t-'A']++;
        }
        priority_queue<int>maxhp;
        for(int c:count){
            if(c>0){
                maxhp.push(c);
            }
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!maxhp.empty()||!q.empty()){
            time++;
            if(maxhp.empty()){
                time=q.front().second;
            }
            else{
                int reducedtime=maxhp.top()-1;
                maxhp.pop();
                if(reducedtime>0){
                    q.push({reducedtime,time+n});
                }
            }
            if(!q.empty()&& q.front().second==time){
                maxhp.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};