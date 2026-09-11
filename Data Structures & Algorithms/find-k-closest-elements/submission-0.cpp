class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int n=arr.size();
        int right=n-k-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(x-arr[mid]<=arr[mid+k]-x){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};