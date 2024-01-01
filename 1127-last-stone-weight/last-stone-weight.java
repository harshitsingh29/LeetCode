class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x : stones) {
            pq.add(x);
        }
        while(!pq.isEmpty()) {
            int k = pq.poll();
            int q = 0;
            if(pq.size() > 0) {
                q = pq.poll();
            }
            if(k == q) {
                continue;
            }
            else {
                pq.add(k-q);
            }
            if(pq.size() == 1) {
                return pq.poll();
            } 
        }
        return 0;
    }
}