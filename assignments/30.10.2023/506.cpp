class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score){
        priority_queue<pair<int,int>> pq;
        vector<string> ans(score.size());

        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        
        for(int i = 0; i < score.size(); i++){
            auto var = pq.top();
            int index = var.second;
            pq.pop();
            if(i == 0){
                ans[index] = "Gold Medal";
            }
            else if(i == 1){
                ans[index] = "Silver Medal";
            }
            else if(i == 2){
                ans[index] = "Bronze Medal";
            }
            else if(i > 2){
                ans[index] = to_string(i + 1);
            }          
        }
        return ans;
    }
};