class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n = t.size()-1;
        vector<int>ans(t.size(),0);
        for(int i=n;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
                st.push(i);
            } else {
                while(!st.empty() && t[st.top()]<=t[i]){
                    st.pop();
                }
                if(st.empty()) {
                    ans[i] = 0;
                } else {
                    ans[i] = st.top()-i;
                }
                st.push(i);
            }
        }
        return ans;
    }
};
