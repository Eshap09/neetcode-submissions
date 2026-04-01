class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        
        for(auto i: nums){
            if(mp[i]){
                return true;
            } else {
                mp[i] = true;
            }
        }
        return false;
    }
};