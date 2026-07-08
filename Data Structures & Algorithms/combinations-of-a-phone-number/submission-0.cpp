class Solution {
private:
    int n = 0;
    static const vector<string> mp;
    // static constexpr string map[10] = {"",    "",    "abc",  "def", "ghi",
    //                                    "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string digits, vector<string>& ans, string path, int i) {
        if (i == n) {
            ans.emplace_back(path);
            return;
        }
        for (char c : mp[digits[i] - '0']) {
            path[i] = c;
            dfs(digits, ans, path, i + 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if (n == 0)
            return {};
        vector<string> ans;
        string path(n, 0);
        dfs(digits, ans, path, 0);
        return ans;
    }
};

const vector<string> Solution::mp = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};
