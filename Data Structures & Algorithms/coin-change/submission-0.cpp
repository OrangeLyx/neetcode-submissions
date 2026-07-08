class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        const int INF = 1e9;
        vector<vector<int>> f(n+1,vector<int>(amount+1,INF));
        for (int i = 0; i <= n; ++i) f[i][0] = 0; // 凑出0金额=0个硬币
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j-coins[i-1]>=0){
                    f[i][j]=min(f[i-1][j],f[i][j-coins[i-1]]+1);
                }else{
                    f[i][j]=f[i-1][j];
                }
            }
        }
        return f[n][amount] == INF ? -1 : f[n][amount];
    }
};
