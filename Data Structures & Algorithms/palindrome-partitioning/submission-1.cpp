class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (this->isPalindrome(s, i, j)) {   // ✅ 用 this->
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};