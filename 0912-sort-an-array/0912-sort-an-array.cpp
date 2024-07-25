class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high) {
        vector<int>arr1, arr2;
        for(int i=low; i<=mid; i++) {
            arr1.push_back(nums[i]);
        }
        for(int i=mid+1; i<=high; i++) {
            arr2.push_back(nums[i]);
        }
        int i = 0, j = 0, k = low;
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) {
                nums[k++] = arr1[i++];
            }
            else {
                nums[k++] = arr2[j++];
            }
        }
        while(i < arr1.size()) {
            nums[k++] = arr1[i++];
        }
        while(j < arr2.size()) {
            nums[k++] = arr2[j++];
        }
    }
    void mergeSort(vector<int>&nums, int low, int high) {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};