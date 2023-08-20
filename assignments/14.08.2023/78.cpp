class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>vec;
        subs(0,nums,vec,answer);
        return answer;

    }
    void subs(int a,vector<int>& nums,vector<int>&vec,vector<vector<int>>&answer) {
        answer.push_back(vec);
        for(int i=a; i<nums.size(); i++){
            vec.push_back(nums[i]);
            subs(i+1,nums,vec,answer);
            vec.pop_back();
        }
    }

};