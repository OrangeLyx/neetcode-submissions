class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path,
             int i) {
        ans.emplace_back(path);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;
            path.push_back(nums[j]);
            dfs(nums, ans, path, j + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(),nums.end());
        dfs(nums, ans, path, 0);
        return ans;
    }
};
