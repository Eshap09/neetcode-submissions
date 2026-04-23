class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int index=0;
       vector<vector<int>> ans;
       vector<int>temp;
       sort(candidates.begin(), candidates.end());
       solve(candidates, ans, temp,index, target); 
       return ans;
    }

    void solve(vector<int>nums, vector<vector<int>>&ans,vector<int>temp,int index,int target){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1,target-nums[i]);
            temp.pop_back();
        }
    }
};
