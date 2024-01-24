class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] adj = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<>();
        }

        int[] inDegree = new int[numCourses];

        // Build the graph and calculate in-degrees
        for (int i = 0; i < prerequisites.length; i++) {
            int a = prerequisites[i][1];
            int b = prerequisites[i][0];
            adj[a].add(b);
            inDegree[b]++;
        }

        // Initialize a queue with nodes having in-degree 0
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }

        int count = 0;

        // Process the nodes
        while (!q.isEmpty()) {
            int current = q.poll();
            count++;

            // Update in-degrees and add neighbors with in-degree 0 to the queue
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }

        // If count is equal to the number of courses, all courses can be finished
        return count == numCourses;
    }
}