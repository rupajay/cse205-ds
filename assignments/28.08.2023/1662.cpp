class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string tem1 = "";
        string tem2 = "";
        for(int i=0;i<word1.size();i++){
          string s = word1[i];
          tem1 += s;
        }
        for(int i=0;i<word2.size();i++){
          string s1 = word2[i];
          tem2 += s1;
        }
        if(tem1 == tem2)
          {
            return true;
          }
        else return false;
    }
};