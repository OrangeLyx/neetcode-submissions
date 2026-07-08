class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sm=(n+1)*n/2;
        int tp=0;
        for(auto & x:nums){
            tp+=x;
        }
        return sm-tp;
    }
};
