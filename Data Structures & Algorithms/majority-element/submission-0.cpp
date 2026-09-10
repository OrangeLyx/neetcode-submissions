class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int cur=0;
        for(auto &num:nums){
            if(cnt==0){
                cur=num;
                cnt++;
            }else if(cur==num){
                cnt++;
            }else if(cur!=num && cnt!=0){
                cnt--;
            }
        }
        return cur;
    }
};