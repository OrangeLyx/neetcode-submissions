class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<vector<bool>> dp(n, vector(n, false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(i==j || j==i+1){
                        dp[i][j]=true;
                    }else if(dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]){
                    res++;
                }
            }
        }
        return res;
    }
};
