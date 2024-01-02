class Solution {
    public int findKthLargest(int[] nums, int k) {
        //Set<Integer> st = new HashSet<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x : nums) {
            //int l = st.size();
            //st.add(x);
            //if(l < st.size()) {
                pq.add(x);
                System.out.print(x);
            //}
        }
        while(k > 1) {
            pq.poll();
            k--;
        }
        return pq.poll();
    }
}