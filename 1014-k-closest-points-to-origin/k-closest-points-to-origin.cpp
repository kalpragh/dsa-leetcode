class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxhp;
        for(auto &pt: points){
            int dist=pt[0]*pt[0]+pt[1]*pt[1];
            maxhp.push({dist,{pt[0],pt[1]}});
            if(maxhp.size()>k){
                maxhp.pop();
            }
        }
        vector<vector<int>>res;
        while(!maxhp.empty()){
            res.push_back({maxhp.top().second.first,maxhp.top().second.second});
            maxhp.pop();
        }
        return res;
    }
};