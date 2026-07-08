class Solution {
    private:
     static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = grid[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);

         while (true) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == n - 1) { // 到终点的最短路已确定
                return d;
            }
            if (d > dis[i][j]) { // (i,j) 之前出堆过
                continue;
            }
            for (auto& [dx, dy] : DIRS) { // 访问相邻的格子
                int x = i + dx, y = j + dy;
                if (0 <= x && x < n && 0 <= y && y < n) {
                    int new_dis = max(d, grid[x][y]);
                    if (new_dis < dis[x][y]) {
                        dis[x][y] = new_dis; // 更新 (i,j) 的邻居的最短路
                        // 懒更新堆：只插入数据，不更新堆中数据
                        pq.emplace(new_dis, x, y);
                    }
                }
            }
        }

    }
};