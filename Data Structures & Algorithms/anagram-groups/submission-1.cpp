class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++){
            string key = strs[i];
            sort(key.begin(), key.end()); 
            //sort(key.begin(),key.end(),greater<char>());  // 降序
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& [key, group] : mp){
            ans.push_back(group);
        }
        return ans;
    }
};
