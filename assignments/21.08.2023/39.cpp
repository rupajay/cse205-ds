class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> datastructure;
        combination(0, target, candidates, answer, datastructure);
        return answer;
    }

    public:
    void combination(int i, int target, vector<int> &arr, vector<vector<int>> &answer, vector<int> &datastructure){
        if(i == arr.size()){
            if(target == 0){
                answer.push_back(datastructure);
            }
            return;
        }

        if(arr[i] <= target){
            datastructure.push_back(arr[i]);
            combination(i, target-arr[i], arr, answer, datastructure);
            datastructure.pop_back();
        }
        combination(i+1, target, arr, answer, datastructure);
    }
};