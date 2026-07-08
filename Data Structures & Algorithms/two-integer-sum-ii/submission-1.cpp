class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int> mp; 
        // for(int i=0;i<nums.size();i++){ 
        //     int val=target-nums[i]; 
        //     if(mp.count(val)) return {mp[val]+1,i+1}; 
        //     mp[nums[i]]=i; 
        // } 
        // return {-1,-1};

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int curSum = nums[l] + nums[r];

            if (curSum > target) {
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                return { l + 1, r + 1 };
            }
        }
        return {};
    }
};
