class Solution {
    public int[] findOrder(int num, int[][] graph) {
        List<Integer>[] adj = new ArrayList[num];
        int[] inDegree = new int[num];
        for(int i = 0; i < num; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < graph.length; i++) {
            int a = graph[i][0];
            int b = graph[i][1];
            adj[a].add(b);
            inDegree[b]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < num; i++) {
            if(inDegree[i] == 0) {
                q.add(i);
            }
        }
        int[] ans = new int[num];
        int i = num-1;
        while(!q.isEmpty()) {
            int k = q.poll();
            ans[i] = k;
            i--;
            for(int it : adj[k]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.add(it);
                }
            }
        }
        if(i == -1) {
            return ans;
        }
        else {
            return new int[]{};
        }
    }
}