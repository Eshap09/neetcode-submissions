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
        int size = nums.size()+1;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pq;
        // for(auto &i:mp){
        //     if(pq.size() <k){
        //         pq.push(i);
        //     } else {
        //         if(pq.top().second<i.second){
        //             pq.pop();
        //             pq.push(i);
        //         }
        //     }
        // }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().first);
        //     pq.pop();
        // }
        // return ans;
        vector<int>ans;
        vector<vector<int>> freq(size+1);
        for(auto &i: mp){
            freq[i.second].push_back(i.first);
        }

        for(int i=size;i>=1;i--){
            for(int j: freq[i]){
                ans.push_back(j);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
