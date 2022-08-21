class Solution {
    
    static bool comp(vector<int>left, vector<int> right) {
        if(left[1] < right[1] || (left[1] == right[1] and left[2] < right[2])) {
            return true;
        }
        else {
            return false;
        }
    }
    
public:
    bool carPooling(vector<vector<int>>& trips, int total) {
        
        sort(trips.begin(), trips.end(), comp);
        int cur = 0;
        int n = trips.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i = 0; i < n; i++) {
            
            while(!pq.empty() and trips[i][1] >= pq.top().first) {
                cur -= pq.top().second;
                pq.pop();
            }
            
            pq.push({trips[i][2], trips[i][0]});
            cur += trips[i][0];
            
            if(cur > total) {
                return false;
            }
        }
        return true;
    }
};