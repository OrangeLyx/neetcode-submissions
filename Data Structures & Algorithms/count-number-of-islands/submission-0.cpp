class Solution {
    private: int ans=0; 
    int m=0,n=0;
    static constexpr int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(grid[i][j]=='0' || grid[i][j]==' ') return;

        grid[i][j]=' ';
        for(auto & [idx,idy] : dir){
            int x=i+idx;
            int y=j+idy;
            if(0<=x && x< m && 0<=y && y< n && grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
