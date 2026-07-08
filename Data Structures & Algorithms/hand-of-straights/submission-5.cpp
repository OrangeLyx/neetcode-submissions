class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int>freq;
        if(n%groupSize!=0)return false;

        for (int card : hand) {
            freq[card]++;
        }
        for (auto &[x, count] : freq) {
            if (count == 0) continue;
            int need = count;
            for (int i = 0; i < groupSize; i++) {
                int card = x + i;
                if (freq[card] < need) {
                    return false;
                }
                freq[card] -= need;
            }
        }
        return true;
    }
};
