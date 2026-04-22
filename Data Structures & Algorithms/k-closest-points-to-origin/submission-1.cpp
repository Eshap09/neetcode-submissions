class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>> >pq;
        for(int i=0;i<points.size();i++){
            int x =points[i][0];
            int y =points[i][1];
            int dist = x*x + y*y;
            pair<int,pair<int,int>> p = {dist, {x,y}};
            if(pq.size()<k){
                pq.push(p);
            } else if(pq.top().first >= dist){
                pq.pop();
                pq.push(p);
            }
        }
        vector<vector<int>>ans;
       while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans.push_back({p.second.first, p.second.second});
        }
        return ans;
    }
};
