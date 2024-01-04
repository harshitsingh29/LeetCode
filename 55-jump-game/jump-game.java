class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if(nums[0] == 0 && n != 1) {
            return false;
        }
        if(nums[0] == 0 && n == 1) {
            return true;
        }
        int i = n-1;
        while(i >= 0) {
            if(nums[i] == 0) {
                int j = i - 1;
                while(j >= 0) {
                    //System.out.println(j);
                    if(((nums[j] - (i-j)) >= 1) || ((nums[j] - (i-j)) == 0 && i == n-1)){
                        i = j;
                        System.out.println(i);
                        break;
                    }
                    else {
                        j--;
                        if(j < 0) {
                            return false;
                        }
                    }
                }
            }
            else {
                i--;
                if(i < 0) {
                    return true;
                }
            }
        }
        return false;
    }
}