class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        int pos=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[pos]=nums[i];
                pos++;
            }
        }
        return pos;
    }
};