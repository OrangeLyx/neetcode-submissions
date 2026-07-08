class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path,
             int i) {
        ans.emplace_back(path);
        for (int j = i; j < nums.size(); j++) {
            path.push_back(nums[j]);
            dfs(nums, ans, path, j + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, ans, path, 0);
        return ans;
    }
};
