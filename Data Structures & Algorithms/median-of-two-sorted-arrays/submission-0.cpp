class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int LeftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int RightA = (i == m) ? INT_MAX : nums1[i];
            int LeftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int RightB = (j == n) ? INT_MAX : nums2[j];

            if (LeftA <= RightB && LeftB <= RightA) {
                if ((m + n) % 2 == 0) {
                    return (max(LeftA, LeftB)+min(RightA, RightB))/2.0;
                } else {
                    return max(LeftA, LeftB);
                }
            } else if (LeftA > RightB) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};
