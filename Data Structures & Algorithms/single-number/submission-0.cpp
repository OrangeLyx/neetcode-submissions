class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或运算
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
