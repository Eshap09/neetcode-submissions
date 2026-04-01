class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j= heights.size()-1;
        int maxm =0;
        while(i<j){
            maxm= max(min(heights[i],heights[j])*(j-i),maxm);
            if(heights[i]>heights[j]){
                j--;
            } else {
                i++;
            }
        }
        return maxm;
    }
};
