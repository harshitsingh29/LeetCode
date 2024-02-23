class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int it : st) {
            int count = 0;
            int k = it-1;
            int t = it+1;
            while(st.find(k) != st.end()) {
                st.erase(k);
                count++;
                k--;
            }
            while(st.find(t) != st.end()) {
                st.erase(t);
                count++;
                t++;
            }
            ans = max(ans, count+1);
        }
        return ans;
    }
};