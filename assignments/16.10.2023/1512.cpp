class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;

        for(int &num : nums){
            count = count + mp[num];
            mp[num]++;
        }
        
        return count;
    }
};