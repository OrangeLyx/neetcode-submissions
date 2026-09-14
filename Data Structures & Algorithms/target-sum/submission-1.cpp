class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2) {
            return 0;
        }

        int m = s / 2; // 背包容量
        int n = nums.size();
        vector f(n + 1, vector<int>(m + 1));
        f[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= m; c++) {
                if (c < nums[i]) {
                    f[i + 1][c] = f[i][c]; // 只能不选
                } else {
                    f[i + 1][c] = f[i][c] + f[i][c - nums[i]]; // 不选 + 选
                }
            }
        }

        return f[n][m];
    }
};