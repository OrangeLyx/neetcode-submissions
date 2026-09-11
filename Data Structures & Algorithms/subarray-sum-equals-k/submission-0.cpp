class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int right=0;
        int ans=0;
        for(int i=0;i<n;i++){
            right+=nums[i];
            int left=0;
            for(int j=0;j<=i;j++){
                left+=nums[j];
                if(right-left+nums[j]==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};