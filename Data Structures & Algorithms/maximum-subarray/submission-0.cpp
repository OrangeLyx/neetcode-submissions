class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sm=0;
        int res=nums[0];
        for(auto num:nums){
            if(sm<=0){
                sm=num;
            }
            else{
                sm+=num;}
            res=max(res,sm);
        }
        return res;
    }
};
