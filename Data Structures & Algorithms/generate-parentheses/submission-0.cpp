class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open =n,close =n;
        vector<string>ans;
        solve(open, close, ans, "");
        return ans;
    }

    void solve(int o, int c, vector<string>&ans, string op){
        if(o == 0 && c ==0) {
            ans.push_back(op);
            return;
        }

        if(o==c && o!=0){
            string op1= op;
            op1 += "(";
            solve(o-1,c,ans,op1);
        } else if(o<c && o!=0){
            string op1 = op;
            string op2 = op;
            op1 += ")";
            op2 += "(";
            solve(o-1,c,ans, op2);
            solve(o,c-1,ans, op1);
        } else{
            string op1 = op;
            op1 +=")";
            solve(o,c-1,ans, op1);
        }
    }
};
