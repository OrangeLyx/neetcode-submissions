class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
        for (auto& t : times) {
            g[t[0] - 1][t[1] - 1] = t[2];
        }
        vector<int> dis(n, INT_MAX / 2);
        dis[k - 1] = 0;

        priority_queue< pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        pq.push({0,k-1});

        while(!pq.empty()){
            auto [len,node]=pq.top();
            pq.pop();
            if(len > dis[node]) continue; // 删除重复

            for(int i=0;i<g[node].size();i++){
                int x=len+g[node][i] ;
                if(x<dis[i]){
                    dis[i]=x;
                    pq.push({x, i});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX/2) return -1;
        }
        return *max_element(dis.begin(), dis.end());;
    }
};