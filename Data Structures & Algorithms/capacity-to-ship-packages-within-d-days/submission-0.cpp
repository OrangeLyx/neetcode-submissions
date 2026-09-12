class Solution {
private:
    bool check(int capacity, vector<int>& weights, int days){
        int need=1;
        int acc=0;
        for(auto &w:weights){
            if(acc+w<=capacity){
                acc+=w;
            }else{
                need++;
                acc=w;
            }
        }
        return need<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        for(auto &w:weights){
            left=max(left,w);
        }
        int right=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(mid,weights,days)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};