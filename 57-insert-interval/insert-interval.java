class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        for(int[] it : intervals) {
            if(newInterval == null || it[1] < newInterval[0]) {
                ans.add(it);
            }
            else if(newInterval[1] < it[0]) {
                ans.add(newInterval);
                ans.add(it);
                newInterval = null;
            }
            else {
                newInterval[0] = Math.min(newInterval[0], it[0]);
                newInterval[1] = Math.max(newInterval[1], it[1]);
            }
        }
        if(newInterval != null) {
            ans.add(newInterval);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}