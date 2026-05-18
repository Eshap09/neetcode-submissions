class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ph = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0) return {};
        dfs(digits, ph, 0, ans, "");
        return ans;
    }

    void dfs(string digits, vector<string>ph, int index, vector<string>&ans, string temp){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }

        string chars = ph[digits[index]-'0'];
        for(char c: chars){
            dfs(digits, ph, index+1,ans, temp+c);
        }
    }
};
