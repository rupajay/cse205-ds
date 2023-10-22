class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        int i = 0;
        string temp = "";
        while(i < s.size()){
            if(s[i] == ' '){
                vec.push_back(temp);
                temp = "";
            }
            else{
                temp = temp + s[i];
            }
            i++;
        }
        vec.push_back(temp);

        if(vec.size() != pattern.size()){
            return false;
        }

        unordered_map<char, string> m;
        set<string> st;

        for(int i = 0; i < pattern.size(); i++){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != vec[i]){
                    return false;
                }
            }
            else{
                if(st.count(vec[i]) > 0){
                    return false;
                }
                m[pattern[i]] = vec[i];
                st.insert(vec[i]);
            }
        }
        return true;
    }
};