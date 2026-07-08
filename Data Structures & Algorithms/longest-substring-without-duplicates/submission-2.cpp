class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int res=1;
        int left=0;
        if(s.size()==0) return 0;
        for(int right=0;right<s.size();right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            res=max(res,right-left+1);
            st.insert(s[right]);
        }
        return res;
    }
};
