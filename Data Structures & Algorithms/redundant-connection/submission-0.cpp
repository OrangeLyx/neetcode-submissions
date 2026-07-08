class Solution {
    private:
    int find(vector<int>&parent, int x){
        if(x!=parent[x]){
            parent[x]=find(parent,parent[x]);
        }
        return parent[x];
    }
    void Union(int a, int b, vector<int> &rank, vector<int>& parent){
        int root_a=find(parent,a);
        int root_b=find(parent,b);
        if(root_a==root_b) return;
        if(rank[root_a]<rank[root_b]){
            parent[root_a]=root_b;
        }else if(rank[root_a]>rank[root_b]){
            parent[root_b]=root_a;
        }else{
            parent[root_a]=root_b;
            rank[root_b]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        vector<int>rank(n+1,0);

        for(auto & edge:edges){
            int x=edge[0];
            int y=edge[1];
            if(find(parent,x)==find(parent,y)){
                return {x,y};
            }
            Union(x,y,rank,parent);
        }
        return {-1,-1};

    }
};