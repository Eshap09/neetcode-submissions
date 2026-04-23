class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size(), m = board[0].size();
       vector<vector<bool>>visited(n, vector<bool>(m, false));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == word[0]){
                if(dfs(board, word, i,j,n,m,visited,0)){
                    return true;
                }
            }
        }
       }
       return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int n, int m , 
        vector<vector<bool>>visited, int index){
            if(index == word.length()) return true;

            if (r < 0 || c < 0 || r >= n || c >= m ||
            board[r][c] != word[index] || visited[r][c] == true) {
            return false;
            }
            visited[r][c] = true;
            bool res = dfs(board, word, r+1,c,n,m,visited,index+1) ||
                        dfs(board, word, r-1,c,n,m,visited,index+1) ||
                        dfs(board, word, r,c+1,n,m,visited,index+1) ||
                        dfs(board, word, r,c-1,n,m,visited,index+1);
            visited[r][c] = false;
            return res;
        }
};
