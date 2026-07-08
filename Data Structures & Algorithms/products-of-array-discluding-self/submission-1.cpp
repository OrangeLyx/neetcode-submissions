class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,1);
        vector<int> back(n,1);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        for(int j=n-2;j>=0;j--){
            back[j]=back[j+1]*nums[j+1];
        }
        vector<int> ans;
        ans.resize(n);
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*back[i];
        }
        return ans;
    }
};
