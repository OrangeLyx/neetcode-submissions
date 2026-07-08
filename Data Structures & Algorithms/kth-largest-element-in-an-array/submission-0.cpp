class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

private:
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        vector<int> big, small, equal;
        for (int num : nums) {
            if (num > pivot) {
                big.push_back(num);
            } else if (num < pivot) {
                small.push_back(num);
            } else {
                equal.push_back(num);
            }
        }
        if (k <= big.size()) {
            return quickSelect(big, k);
        }
        if (nums.size() - k < small.size()) {
            return quickSelect(small, small.size() - nums.size() + k);
        }
        return pivot;
    }
};
