class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 最多多少个互不重叠的区间
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans=0;
        int pre_r=INT_MIN;
        for(auto & p:intervals){
            if(p[0]>=pre_r){
                ans++;
                pre_r=p[1];
            }
        }
        return intervals.size()-ans;
    }
};
