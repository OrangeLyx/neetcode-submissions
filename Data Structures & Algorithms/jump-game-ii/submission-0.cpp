class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        int end=0;
        int dump=0;
        for(int i=0;i<n-1;i++){
            mx=max(mx,i+nums[i]);
            if(i==end){
                end=mx;
                dump++;
            }
        }
        return dump;
    }
};
