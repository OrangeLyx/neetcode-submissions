class Solution {
    private:
    void best(int i,int j,vector<vector<int>>& store,vector<int>& nums){
        int candidate=0;
        for(int k=i+1;k<j;k++){
            int left=store[i][k];
            int right=store[k][j];
            candidate=max(candidate,left+right+nums[i]*nums[k]*nums[j]);
        }
        store[i][j]=candidate;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> store(n,vector<int>(n,0));

        for(int len=2;len<n;len++){
            for(int i=0;i<n-len;i++){
                best(i,i+len,store,nums);
            }
        }
        return store[0][n-1];
    }
};