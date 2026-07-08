class Solution {
    private:
    void dfs(const vector<vector<int>>& adj,vector<bool> &visit,int node){
        visit[node]=true;
        for(int ne:adj[node]){
            if(!visit[ne]){
                dfs(adj,visit, ne);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n,false);
        for(const auto & e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res=0;
        for(int node=0;node<n;node++){
            if(!visit[node]){
                dfs(adj,visit,node);
                res++;
            }
        }
        return res;
    }
};
