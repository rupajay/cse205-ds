class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
         int cnt=0;
        while(cnt!=k){
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }       
        return ans;
    }
};