class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = (int)s1.size(), m = (int)s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), win(26, 0);
        for (char c : s1) need[c - 'a']++;

        for (int i = 0; i < n; i++) win[s2[i] - 'a']++;
        if (win == need) return true;

        // slide
        for (int i = n; i < m; i++) {
            win[s2[i] - 'a']++;            // add right
            win[s2[i - n] - 'a']--;        // remove left
            if (win == need) return true;
        }
        return false;
    }
};
