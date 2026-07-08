class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = 0;
        for (const auto& w : wordDict) {
            if (w.length() > max_len)
                max_len = w.length();
        }
        int n=s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> f(n+1,false);
        f[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=i-1;j>=max(0,i-max_len);j--){
                if(f[j] && words.count(s.substr(j,i-j))){
                    f[i]=true;
                    break;
                }
            }
        }

        return f[n];
    }
};
