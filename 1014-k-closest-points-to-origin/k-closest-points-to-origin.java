class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int n = points.length;
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(a[0],b[0]));
        for(int i = 0; i < n; i++) {
            double a = Math.pow(points[i][0], 2) + Math.pow(points[i][1], 2);
            pq.add(new double[]{a,i});
        }
        int[][] res = new int[k][2];
        for(int i = 0; i < k; i++) {
            double[] ans = pq.poll();
            int j = (int)ans[1];
            res[i][0] = (int)points[j][0];
            res[i][1] = (int)points[j][1];
        }
        return res;
    }
}