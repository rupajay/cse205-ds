class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.push(nums[i]);
        }

        int first = ans.top();
        ans.pop();
        int second = ans.top();

        return (first-1)*(second-1);
    }
};