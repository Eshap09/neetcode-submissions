class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int prdt =1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                prdt*=nums[j];
            }
            ans.push_back(prdt);
        }
        return ans;
    }

};
