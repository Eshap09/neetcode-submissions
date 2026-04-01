class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        unordered_map<int,unordered_set<char>>rows,cols;
        map<pair<int,int>,unordered_set<char>>squares;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                    if(b[r][c] == '.') continue;
                    pair<int,int> squarekey = {r/3,c/3};

                    if(rows[r].count(b[r][c]) || cols[c].count(b[r][c]) ||
                    squares[squarekey].count(b[r][c])
                    ) {
                        return false;
                    }
                   
                   rows[r].insert(b[r][c]);
                   cols[c].insert(b[r][c]);
                   squares[squarekey].insert(b[r][c]);
            }
        }
        return true;
    }
};
