class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end());
        if (s % 2)
            return false;
        s /= 2;
        int n = nums.size();
        vector f(n + 1, vector<int>(s + 1));
        f[0][0] = true;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 0; j <= s; j++) {
                f[i + 1][j] = j >= x && f[i][j - x] || f[i][j];
            }
        }
        return f[n][s];
    }
};