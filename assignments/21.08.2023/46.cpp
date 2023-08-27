class Solution {
    private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &answer, int fr[]){
        if(ds.size() == nums.size()){
        answer.push_back(ds);
        return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(!fr[i]){
                ds.push_back(nums[i]);
                fr[i] = 1;
                recurPermute(ds, nums, answer, fr);
                fr[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>ds;
        int fr[nums.size()];
        for(int i=0;i<nums.size();i++) fr[i]=0;
        recurPermute(ds, nums, answer, fr);
        return answer;
    }
};