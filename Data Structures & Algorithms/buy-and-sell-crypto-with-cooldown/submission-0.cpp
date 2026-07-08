class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 2, vector<int>(2));
        f[1][1] = INT_MIN;
        for (int i = 0; i < n; i++) {
            f[i + 2][0] = max(f[i + 1][0], f[i + 1][1] + prices[i]);
            f[i + 2][1] = max(f[i + 1][1], f[i][0] - prices[i]);
        }
        return f[n + 1][0];
    }
};
