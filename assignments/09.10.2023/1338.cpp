class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int m=n/2;
        
        map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        int sum=n;
        int count=0;
        while(!pq.empty()){
            int c=pq.top().first;
            sum-=c;
            count++;
            if(sum<=n/2){
                return count;
            }
            pq.pop();
        }
        return count;
    }
};