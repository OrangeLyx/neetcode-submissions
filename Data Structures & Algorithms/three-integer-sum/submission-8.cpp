class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if (i && x == nums[i - 1]) {
                continue;
            }
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sm=nums[left]+nums[right]+x;
                if(sm>0){
                    right--;
                }else if(sm<0){
                    left++;
                }else{
                    ans.push_back({x,nums[left],nums[right]});
                    for(left++;left<right && nums[left]==nums[left-1];left++);
                    for(right--;left<right && nums[right]==nums[right+1];right--);
                }
            }
        }
        return ans;
    }
};
