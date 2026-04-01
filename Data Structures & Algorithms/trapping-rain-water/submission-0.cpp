class Solution {
public:
    int trap(vector<int>& heights) {
        stack<int>s;
        int n = heights.size();
        vector<int>gr(n,0);
        vector<int>gl(n,0);
        // s.push(-1);
        for(int i=n-1;i>=0;i--){
           while(!s.empty() && s.top()<heights[i]){
                s.pop();
           }
           if(s.empty()){
            gr[i]=0;
            s.push(heights[i]);
           } else {
                gr[i]= s.top();
           }
           cout<<gr[i]<< " ";
        }
        cout<<endl;
        stack<int>q;
        for(int i=0;i<n;i++){
             while(!q.empty() && q.top()<heights[i]){
                q.pop();
           }
           if(q.empty()){
            gl[i]=0;
            q.push(heights[i]);
           } else {
                gl[i]= q.top();
           }
           cout<<gl[i]<<" ";
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int temp =  min(gr[i],gl[i])-heights[i];
            if(temp>0){
                ans+= temp;
            }
        }
        return ans;
    }
};
