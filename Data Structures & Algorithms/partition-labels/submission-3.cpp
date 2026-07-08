class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);

        int n = s.size();

        // 记录每个字母最后一次出现的位置
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);

            // 如果当前 i 已经到达这个 partition 的最远边界
            // 说明可以切一刀
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
