class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() != 0){
            if(pq.size() == 1){
                return pq.top();
                pq.pop();
            }
            else if(pq.size() == 2){
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
                return abs(first-second);
            }
            else if(pq.size() > 2){
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
                if(first != second){
                    pq.push(abs(first-second));
                }
            }
        }
        return 0;
    }
};