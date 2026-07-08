class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans(n - k + 1);

        for (int i = 0; i < n; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            int left = i - k + 1;
            if (q.front() < left) {
                q.pop_front();
            }
            if (left >= 0) {
                ans[left] = nums[q.front()];
            }
        }
        return ans;
    }
};
