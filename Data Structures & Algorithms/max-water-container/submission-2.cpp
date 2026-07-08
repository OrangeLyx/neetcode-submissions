class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int res=0;
        while(i<j){
            if(heights[i]<heights[j]){
                // 保留更小的边
                res=max(res,(j-i)*heights[i]);
                i++;
            }else{
                res=max(res,(j-i)*heights[j]);
                j--;
            }
        }
        return res;
    }
};
