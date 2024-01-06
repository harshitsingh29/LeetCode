class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if(n == 1 || n == 2) {
            return n-1;
        }
        int i = 0;
        int count = 1;
        if(nums[0] >= n-1) {
            return 1;
        }
        while(i < n) {
            //int k = nums[i];
            int e = Math.min(nums[i]+i+1, n);
            int max = 0, newi = i+1;
            count++;
            for(int j = i+1; j < e; j++) {
                if(nums[j] != 0) {
                    if(j + nums[j] >= n-1) {
                        //System.out.println(nums)
                        return count;
                    }
                    else {
                        if(j + nums[j] > max) {
                            max = j + nums[j];
                            i = j;
                            System.out.println(newi);
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
            //i = newi;
        }
        return count;
    }
}