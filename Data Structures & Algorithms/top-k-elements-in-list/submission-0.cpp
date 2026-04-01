class Solution {
public:

    struct Cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second; //max priority is second now.
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
        for(auto &i:mp){
            if(pq.size() <k){
                pq.push(i);
            } else {
                if(pq.top().second<i.second){
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
