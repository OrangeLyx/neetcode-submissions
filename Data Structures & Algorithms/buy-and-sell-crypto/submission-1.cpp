class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mx=INT_MAX;
        for(int p:prices){
            res=max(res,p-mx);
            mx=min(mx,p);
        }
        return res;
    }
};
