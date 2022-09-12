class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0, j = n-1;
        int ans = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        for(int k = 0; k < n; k++) {
            if(power > tokens[i] || (power >= tokens[i] and i == j)) {
                power -= tokens[i];
                score += 1;
                i++;
            }
            else if(score >= 1){
                power += tokens[j];
                score -= 1;
                j--;
            }
            cout<<score<<" "<<power<<" ";
            ans = max(ans, score);
        }
        return ans;
    }
};