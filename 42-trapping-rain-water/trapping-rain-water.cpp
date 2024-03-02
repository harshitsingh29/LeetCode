class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
        if (n == 0) return 0;
        
        int leftMax = height[0];
        int rightMax = height[n - 1];
        int left = 0, right = n - 1;
        int ans = 0;
        
        while (left <= right) {
            if (leftMax <= rightMax) {
                ans += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++;
            } else {
                ans += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        
        return ans;
        }
};