class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length == 1) {
            return intervals;
        }
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> ans = new ArrayList<>();
        int[] temp = intervals[0];
        for(int[] it : intervals) {
            if(it[0] <= temp[1]) {
                temp[1] = Math.max(temp[1], it[1]);   
            }
            else {
                ans.add(temp);
                temp = it;
            }
        }
        ans.add(temp);
        return ans.toArray(new int[ans.size()][]);
    }   
}