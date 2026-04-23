class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       int index=0;
       vector<vector<int>> ans;
       vector<int>temp;
       solve(nums, ans, temp,index, target); 
       return ans;
    }

    void solve(vector<int>nums, vector<vector<int>>&ans,vector<int>temp,int index,int target){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;

        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i,target-nums[i]);
            temp.pop_back();
        }
    }
};
