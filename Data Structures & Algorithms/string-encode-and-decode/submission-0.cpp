class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto &i: strs){
            ans+=i+"-";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0,j=0;
        while(j<s.length()){
            if(s[j]=='-'){
                ans.push_back(s.substr(i,j-i));
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};
