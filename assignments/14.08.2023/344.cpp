class Solution {
public:
        void reversevalue(int x,vector<char>& s){
            if(x>=s.size()/2){
                return;
            }
            swap(s[x],s[s.size()-x-1]);
            reversevalue(x+1,s);
        }
    void reverseString(vector<char>& s) {
        reversevalue(0,s);
    }
};
