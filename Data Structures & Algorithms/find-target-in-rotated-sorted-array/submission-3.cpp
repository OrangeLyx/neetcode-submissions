class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<nums[mid]){ //单调的条件很好写
                    right=mid-1;
                }else{ // 不好写
                    left=mid+1;
                }
            }else{
                if(target>nums[mid] && target<= nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
