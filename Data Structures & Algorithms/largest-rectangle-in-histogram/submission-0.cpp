class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int>nsr(size,0);
        vector<int>nsl(size,0);
        stack<int>st;
        for(int i=size-1;i>=0;i--){
            if(st.empty()){
                nsr[i]=size;
            } else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i]= size;
                } else {
                    nsr[i] = st.top();
                }     
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
         for(int i=0;i<size;i++){
            if(st.empty()){
                nsl[i]=-1;
            } else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i]= -1;
                } else {
                    nsl[i] = st.top();
                }
                
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<size;i++){
            ans = max(ans, heights[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;

    }
};
