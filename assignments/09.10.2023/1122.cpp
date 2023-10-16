class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int s = 0;
        int e = arr1.size() - 1;

        mergesort1(arr1, s, e);
        
        vector<int> ans;

        

        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < arr1.size(); j++){
                if(arr2[i] == arr1[j]){
                    ans.push_back(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }

        for(int i = 0; i < arr1.size(); i++){
            if(arr1[i] != -1){
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }

    void merge(vector<int>& nums, int s, int e){
        int mid = s + (e - s)/2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int arr1[len1];
        int arr2[len2];

        int mainIndex = s;

        for(int i = 0; i < len1; i++){
            arr1[i] = nums[mainIndex++];
        }

        mainIndex = mid + 1;

        for(int j = 0; j < len2; j++){
            arr2[j] = nums[mainIndex++];
        }
        
        int index1 = 0;
        int index2 = 0;
        mainIndex = s;

        while(index1 < len1 && index2 < len2){
            if(arr1[index1] > arr2[index2]){
                nums[mainIndex++] = arr2[index2++];
            }
            else{
                nums[mainIndex++] = arr1[index1++];
            }
        }

        while(index1 < len1){
            nums[mainIndex++] = arr1[index1++];
        }
        while(index2 < len2){
            nums[mainIndex++] = arr2[index2++];
        }
    }

    void mergesort1(vector<int>& nums, int s, int e){
        if(s >= e){
            return;
        }

    int mid = s + (e - s)/2;

    mergesort1(nums, s, mid);
    mergesort1(nums, mid + 1, e);

    merge(nums, s, e);
    }
};