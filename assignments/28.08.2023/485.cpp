class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int num = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                counter++;
            }
            else{
                num = max(counter,num);
                counter = 0;
            }
            num = max(counter,num);
        }
        return num;
    }
};