class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for( int n:nums){
            if(set.count(n)) return true;
            set.insert(n);
        }
        return false;
    }
};