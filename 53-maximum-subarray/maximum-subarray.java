class Solution {
    public int maxSubArray(int[] nums) {
        int curr_max = 0, max_end = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            curr_max += nums[i];
            if(curr_max > max_end) {
                max_end = curr_max;
            }
            if(curr_max < 0) {
                curr_max = 0;
            }
        }
        return max_end;
    }
}