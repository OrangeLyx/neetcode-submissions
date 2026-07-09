class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        for(int i=n-1;i>=0;i--){
            int & cur=digits[i];
            if(i==n-1){
                cur++;
            }
            if(carry==1){
                cur+=carry;
            }
            if(cur==10){
                cur=0;
                carry=1;
            }else{
                carry=0;
            }
        }
        if(carry==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
