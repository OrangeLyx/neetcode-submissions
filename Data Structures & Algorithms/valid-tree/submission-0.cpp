class Solution {
    private: void dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int nei : graph[node]) {
            if (nei == parent) continue; // 避免无限递归
            if (visited[nei]) continue;  // already visited → no need to check, n-1 edges ensure no cycle
            dfs(nei, node, graph, visited);
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        dfs(0, -1, graph, visited);

        for (bool v : visited)
            if (!v) return false;
        return true;
    }
};
