class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>edge(numCourses);
        vector<int>ans;
        // 使用邻接表记录边情况以及入度度数
        for(int i = 0; i < prerequisites.size(); i++){
            int ai = prerequisites[i][0];
            int bi = prerequisites[i][1];
            indegree[ai] += 1;
            edge[bi].push_back(ai);
        }

        // 拓扑排序的过程
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int i = 0; i < edge[u].size(); i++){
                int v = edge[u][i];
                indegree[v] -= 1;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }


};
