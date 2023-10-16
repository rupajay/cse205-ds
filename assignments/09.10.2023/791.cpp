class Solution {
public:
    string customSortString(string order, string s) {
        string ans;        
        for(int i=0;i<order.size();i++){
            for(int j=0;j<s.size();j++){
                if(order[i]==s[j]){
                    ans.push_back(s[j]);
                    s[j]='0';
                }
            }          
        }         
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ans.push_back(s[i]);
            }           
        }
        return ans;
        
    }
};