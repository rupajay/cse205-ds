class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>answer;
        vector<int>vect;
        solve(n,k,answer,vect);
        return answer;
    }

 void solve(int n,int k,vector<vector<int>>&answer,vector<int>&vect)
 {
         if(vect.size()==k)
        {
         answer.push_back(vect);
         return;
        }
        if(n==0)
        {
         return;
        }

        vect.push_back(n);
        solve(n-1,k,answer,vect); 
        vect.pop_back();
        solve(n-1,k,answer,vect);
 }    
    
};