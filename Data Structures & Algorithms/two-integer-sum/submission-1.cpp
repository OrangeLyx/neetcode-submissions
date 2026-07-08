class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            // int val = nums[i] - target;  两数之差
            if(mp.count(val)) return {mp[val],i};
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
