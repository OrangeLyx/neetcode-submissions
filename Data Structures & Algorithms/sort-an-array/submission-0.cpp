class Solution {
    private:
    int n;
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int>tmp;
        int k=0;
        int i=left,j=mid+1;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                tmp.push_back(nums[i]);
                i++;
            }else{
                tmp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            tmp.push_back(nums[i]);
            i++;
        }
        while(j<=right){
            tmp.push_back(nums[j]);
            j++;
        }
        while(k<tmp.size()){
            nums[k+left]=tmp[k];
            k++;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};