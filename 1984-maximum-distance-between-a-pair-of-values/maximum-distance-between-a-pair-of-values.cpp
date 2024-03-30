class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i < m && A[i] <= B[i]) {
                int count = 0;
                int left = i;
                int right = m-1;
                int result = -1;
                int k = A[i];
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (B[mid] >= k) {
                        result = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                ans = max(ans, result-i);
            }
            else {
                continue;
            }
        }
        return ans;
    }
};