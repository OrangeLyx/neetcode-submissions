class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n,0);
        for(int i=0;i<n;i++){
            f[i]=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    f[i]=max(f[i],f[j]);
                }
            }
            f[i]++;
        }
        return *max_element(f.begin(),f.end());
    }
};
