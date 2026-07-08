class Solution {
private:
    int n = 0;
    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& on_path,
             vector<int>& nums, int i) {
        if (i == n) {
            ans.emplace_back(path);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!on_path[j]) {
                path[i] = nums[j];
                on_path[j] = true;
                dfs(ans, path, on_path, nums, i + 1);
                on_path[j] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<int> on_path(n);
        dfs(ans, path, on_path, nums, 0);
        return ans;
    }
};
