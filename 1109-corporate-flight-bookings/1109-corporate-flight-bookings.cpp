class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>res(n, 0);
        vector<int>change(n+1, 0);
        for(int i = 0; i < bookings.size(); i++) {
            res[bookings[i][0] - 1] += bookings[i][2];
            change[bookings[i][1]] -= bookings[i][2];
        }
        for(int i = 1; i < n; i++) {
            res[i] += res[i-1];
            res[i] += change[i];
        }
        return res;
    }
};