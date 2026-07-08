class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) {
            return 0;
        }

        vector f(n + 1, vector<unsigned>(m + 1));
        
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = 1;
            for (int j = 0; j < min(i + 1, m); j++) {
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j + 1]+f[i][j];
                }else{
                     f[i + 1][j + 1] = f[i][j + 1];
                }
            }
        }
        return f[n][m];
    }
};