class Solution {
private:
    vector<string> ans;
    void dfs(int left, int right, string path, int n) {
        if (right == n) {
            ans.emplace_back(path);
            return;
        }
        if (left < n) {
            path[left + right] = '(';
            dfs(left + 1, right, path, n);
        }
        if (left > right) {
            path[left + right] = ')';
            dfs(left, right + 1, path, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string path(n * 2, 0);
        dfs(0, 0, path, n);
        return ans;
    }

};
