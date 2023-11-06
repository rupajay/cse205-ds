class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even, odd;
        vector<int> makeArray, forMax;

        while(num > 0){
            int last = num % 10;
            if(last % 2 == 0){
                even.push(last);
            }
            else{
                odd.push(last);
            }
            num = num / 10;
            makeArray.push_back(last);
        }

        reverse(makeArray.begin(), makeArray.end());

        for(int i = 0; i < makeArray.size(); i++){
            if(makeArray[i] % 2 == 0){
                forMax.push_back(even.top());
                even.pop();
            }
            else{
                forMax.push_back(odd.top());
                odd.pop();
            }
        }

        int ans = 0;
        for(int i = 0; i < forMax.size(); i++){
            ans  = (ans * 10) + forMax[i];
        }
        return ans;
    }
};