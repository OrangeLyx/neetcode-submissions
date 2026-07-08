class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 纯模拟
        //After sorting cars from closest to the target to farthest, we calculate how long each one needs to reach the target.
        // A car forms a new fleet only if it takes longer than the fleet in front of it.
        
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());

        int fleets = 1;
        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
