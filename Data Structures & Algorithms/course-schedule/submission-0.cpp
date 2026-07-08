class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> irate(numCourses, 0); 
        vector<vector<int>> rel(numCourses, vector<int>{});
        for(auto & course: prerequisites){
            int pre=course[1],cur=course[0];
            irate[cur]++; // 有几门先修课
            rel[pre].push_back(cur);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (irate[i] == 0) 
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int fina=q.front();
            q.pop();
            cnt++;

            for(auto pre:rel[fina]){
                irate[pre]--;
                if(irate[pre]==0){
                    q.push(pre);
                }
            }
        }
        return cnt==numCourses;
    }
};
