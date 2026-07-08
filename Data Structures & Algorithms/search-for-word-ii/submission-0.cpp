class Solution {
    private: 
    bool flag = false;
    int m, n;
    string w;
    static constexpr int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i, int j, vector<vector<char>>& board, int idx) {                
        if (idx + 1 == w.size()) {          
            flag = true;
            return;
        }
        char tmp = board[i][j];
        board[i][j] = ' ';                  
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (0 <= ni && ni < m && 0 <= nj && nj < n && board[ni][nj] == w[idx + 1]) {
                dfs(ni, nj, board, idx + 1);
                // if (flag) break;
            }
        }
        board[i][j] = tmp;                
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string> & words) {
        m=board.size();
        n=board[0].size();
        vector<string> ans;
        for(auto & word: words){
            flag = false;  
            w = word;   
            for(int i=0;i<m && !flag;i++){
                for(int j=0;j<n && !flag;j++){
                    if(w[0]==board[i][j]){
                        dfs(i,j,board,0);
                    }
                }
            }
            if (flag) ans.push_back(w);
        }
        return ans;
    }
};
