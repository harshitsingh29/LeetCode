class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int n = A.size();
        vector<int> temp = A;
        sort(temp.begin(), temp.end());
        int indf = 0, inds = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] != temp[i]) {
                indf = i;
                break;
            }
        }
        for(int i = n-1; i >= indf; i--) {
            if(A[i] != temp[i]) {
                inds = i;
                break;
            }
        }
        if(indf == 0 && inds == 0) {
            return 0;
        } 
        return inds - indf + 1;
    }
};