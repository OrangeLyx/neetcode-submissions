class CountSquares {
private:
    map<pair<int, int>, int> cnt;
    vector<pair<int, int>> points;
public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        cnt[{x, y}]++;
        points.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        for (auto [dx, dy] : points) {
            if (dx == x || dy == y) continue;
            // must form a square, not just a rectangle
            if (abs(dx - x) != abs(dy - y)) continue;
            pair<int, int> p1 = {x, dy};
            pair<int, int> p2 = {dx, y};
            ans += cnt[p1] * cnt[p2];
        }
        return ans;
    }
};