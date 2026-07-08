class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first=false;
        bool second=false;
        bool last=false;
       for (auto& t : triplets) {
            int x = t[0], y = t[1], z = t[2];
            // 只考虑不会超过 target 的 triplet
            if (x <= target[0] && y <= target[1] && z <= target[2]) {
                if (x == target[0]) first = true;
                if (y == target[1]) second = true;
                if (z == target[2]) last = true;
            }
        }
        return first && second && last;
    }
};
