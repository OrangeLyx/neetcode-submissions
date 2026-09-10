class Solution {
    string pairCheck(string x, string y){
        int n=x.size();
        int m=y.size();
        int len=min(m,n);
        int i=0;
        while(i<n){
            if(x[i]!=y[i]){
                return x.substr(0,i);
            }
            i++;
        }
        return x;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        if(n==1) return strs[0];
        string ans=strs[0];
        int len=strs[0].size();
        for(int i=1;i<n;i++){
            string pre=pairCheck(strs[i-1],strs[i]);
            if(pre.size()<len){
                ans=pre;
                len=pre.size();
            }
        }
        return ans;
    }
};