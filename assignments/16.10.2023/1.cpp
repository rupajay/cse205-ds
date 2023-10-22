class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int y = target - x;
            if(mp.find(y) != mp.end()){
                return {i, mp[y]};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};