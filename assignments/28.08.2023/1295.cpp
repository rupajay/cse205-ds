class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int counter = 0;
        for(int i=0; i<=nums.size()-1; i++){
            string str = to_string(nums[i]);
            if(str.size()%2==0){
                counter++;
            }

        }
        return counter;
    }
};