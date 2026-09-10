class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.length(),n=t.length();
        if(m!=n) return false;
        unordered_map<char,int> mp;
        for(char ss:s){
            mp[ss]++;
        }
        for(char tt:t){
            if(!mp.count(tt))return false;
            mp[tt]--;
            if(mp[tt]<0) return false;
        }
        return true;
    }
};
