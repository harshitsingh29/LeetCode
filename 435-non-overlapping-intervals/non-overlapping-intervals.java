class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // if(intervals.length == 1) {
        //     return 0;
        // }
        // Arrays.sort(intervals, Comparator.<int[], Integer>comparing(subArray -> subArray[0]).thenComparing(subArray -> subArray[1]));
        // for(int[] it : intervals) {
        //     System.out.println(it[0] + " " + it[1]);
        // }
        // int ans = 0;
        // for(int i = 0; i < intervals.length-1; i++) {
        //     int a = intervals[i][0];
        //     int b = intervals[i][1];
        //     int j = i+1;
        //     while(j < intervals.length && b > intervals[j][0]) {
        //         ans++;
        //         j++;
        //         System.out.println(a + " " + b);
        //     }
        //     i = j-1;
        // }
        // return ans;


        if (intervals.length == 1) {
            return 0;
        }

        Arrays.sort(intervals, Comparator.comparingInt(subArray -> subArray[1]));

        int ans = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            int start = intervals[i][0];

            if (start < end) {
                // Overlapping intervals found
                ans++;
            } else {
                // Non-overlapping interval, update the end time
                end = intervals[i][1];
            }
        }

        return ans;
    }
}