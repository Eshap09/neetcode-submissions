class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int index=0;
       vector<vector<int>> ans;
       sort(nums.begin(), nums.end());
       vector<int>temp;
       solve(nums, ans, temp,index); 
       return ans;
    }

    void solve(vector<int>nums, vector<vector<int>>&ans,vector<int>temp,int index){
        
            ans.push_back(temp);

        if(index == nums.size()) return;
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
};
