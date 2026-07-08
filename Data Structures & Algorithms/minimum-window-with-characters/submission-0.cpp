class Solution {
    private: 
    bool covers(const unordered_map<char,int>& s_mp, const unordered_map<char,int>& t_mp) {
        for (auto& [c, count] : t_mp) {
            if (s_mp.find(c) == s_mp.end() || s_mp.at(c) < count)
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_mp;
        unordered_map<char,int> s_mp;
        for (char c : t) t_mp[c]++;
        
        int n = s.size();
        int i = 0, minLen = INT_MAX, start = 0;
        for (int j = 0; j < n; j++) {
            s_mp[s[j]]++; 
            while (covers(s_mp, t_mp)) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                s_mp[s[i]]--;
                i++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
