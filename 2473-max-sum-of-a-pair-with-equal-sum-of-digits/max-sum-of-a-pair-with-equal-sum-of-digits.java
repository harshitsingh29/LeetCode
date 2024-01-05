class Solution {
    public int maximumSum(int[] nums) {
        HashMap<Integer, int[]> mp = new HashMap<>();
        int n = nums.length;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int k = nums[i];
            int sum = 0;
            while(k != 0) {
                int a = k % 10;
                sum += a;
                k = k / 10;
            }
            int[] pair = mp.getOrDefault(sum, new int[]{0,0});
            if(nums[i] < pair[1]) {
                continue;
            }
            else {
                if(nums[i] > pair[0]) {
                    pair[1] = pair[0];
                    pair[0] = nums[i];
                }
                else {
                    pair[1] = nums[i];
                }
                System.out.println(sum+" "+pair[0] +" "+ pair[1]);
                mp.put(sum, pair);
            }
            // pair[1] = nums[i];
            // if(pair[1] > pair[0]) {
            //     int temp = pair[1];
            //     pair[1] = pair[0];
            //     pair[0] = temp;
            // }
            // System.out.println(sum+" "+pair[0] +" "+ pair[1]);
            // mp.put(sum, pair);
        }
        for(int[] pair : mp.values()) {
            int d = pair[0]+pair[1];
            System.out.println(d);
            if(pair[1] == 0) {
                continue;
            }
            ans = Math.max(ans, pair[0] + pair[1]);
        }
        return ans;
    }
}