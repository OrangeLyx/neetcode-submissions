class Solution {
    private:
    void dfs(vector<int> & nums,int target,vector<vector<int>> & ans,vector<int> & path,int acc,int idx){
        if(acc==target){
            ans.push_back(path);
            return;
        }
 
        for(int i=idx;i<nums.size();i++){
            if(acc+nums[i]<=target){
                path.push_back(nums[i]);
                dfs(nums,target,ans,path,acc+nums[i],i);
                path.pop_back();
            }
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>path;
        dfs(nums,target,ans,path,0,0);
        return ans;
    }
};
