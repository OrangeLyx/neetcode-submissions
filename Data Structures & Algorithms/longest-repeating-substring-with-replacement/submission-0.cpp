class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freqs;
        int res = 0, i = 0, maxFreq = 0;
       
        for (int j = 0; j < s.size(); j++) {
            freqs[s[j]]++;
            maxFreq = max(maxFreq, freqs[s[j]]);
            // maxfreq 当前窗口中出现次数最多的字符频率
            while ((j - i + 1) > k+maxFreq) {
                freqs[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;

    }
};
