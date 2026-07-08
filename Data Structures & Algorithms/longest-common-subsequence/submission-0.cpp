class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> f(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i]==text2[j]){
                    f[i+1][j+1]=f[i][j]+1;
                }else{
                    f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
                }
            }
        }
        return f[m][n];
    }
};
