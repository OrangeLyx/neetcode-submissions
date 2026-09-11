class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos=1;
        int i=1;
        int n=nums.size();
        int pre=nums[0];
        while(i<n){
            while(i<n && pre==nums[i]){
                i++;
            }
            if (i == n) break;
            nums[pos]=nums[i];
            pos++;
            pre=nums[i];
        }
        return pos;
    }
};