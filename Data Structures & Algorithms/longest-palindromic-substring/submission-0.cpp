class Solution {
public:
    string longestPalindrome(string s) {
        int reslen=0;
        int n=s.size();
        string res;
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
                if(dp[i][j]&& (j-i+1>reslen)){
                    reslen=max(j-i+1,reslen);
                    res=s.substr(i,reslen);
                }
            }
        }
        return res;
    }
};
