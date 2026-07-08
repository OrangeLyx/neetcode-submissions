class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        for(auto & p:intervals){
            if(!res.empty() && res.back()[1]>=p[0]){
                res.back()[1] = p[1]>=res.back()[1] ? p[1]: res.back()[1];
            }else{
                res.emplace_back(p);
            }
        }
        return res;
    }
};
