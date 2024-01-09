class Solution {

    public boolean mergeTriplets(int[][] triplets, int[] target) {
        boolean m1 = false, m2 = false, m3 = false;
        for (int i = 0; i < triplets.length; i++) {
            int a = triplets[i][0], b = triplets[i][1], c = triplets[i][2];
            if(a > target[0] || b > target[1] || c > target[2]) {
                continue;
            }
            if(a == target[0]) {
                m1 = true;
            }
            if(b == target[1]) {
                m2 = true;
            }
            if(c == target[2]) {
                m3 = true;
            }
        }
        return m1 && m2 && m3;
    }
}
