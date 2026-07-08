class Solution {
    private:
    int m=0;
    int n=0;
    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& matrix, int x, int y){
        int cur=matrix[x][y];
        matrix[x][y]=-1;
        int ans=0;

        for(auto d:directions){
            int new_x=x+d[0];
            int new_y=y+d[1];
            if(0<= new_x && new_x<m && 0<= new_y && new_y < n && matrix[new_x][new_y]>cur){
                ans=max(ans,dfs(matrix,new_x,new_y));
            }
        }
        matrix[x][y]=cur;
        return ans+1;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();

        int res=-1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,i,j));
            }
        }
        return res;
    }
};
