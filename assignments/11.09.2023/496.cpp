class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> st;
        int n = nums2.size();

        for(int i=n-1; i>=0; i--){
            int element = nums2[i];
            while(!st.empty() && st.top() <= element){
                st.pop();
            }
            int result = (st.empty()) ? -1 : st.top();
            umap.insert({element, result});
            st.push(element);
        }

        vector<int> answer;
        for(auto i: nums1){
            answer.push_back(umap[i]);
        }
        return answer;
    }
};