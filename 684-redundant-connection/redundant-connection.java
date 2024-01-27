class Solution {
    private int[] parent;

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        parent = new int[n + 1]; // We add 1 to the number of edges to handle 1-based indexing
        Arrays.fill(parent, -1);

        for (int[] edge : edges) {
            if (isCyclic(edge)) {
                return edge;
            }
            union(edge);
        }

        return new int[0]; // In case there is no redundant connection (should not happen for this problem)
    }

    private int find(int vertex) {
        if (parent[vertex] == -1) {
            return vertex;
        }
        return find(parent[vertex]);
    }

    private void union(int[] edge) {
        int rootU = find(edge[0]);
        int rootV = find(edge[1]);

        if (rootU != rootV) {
            parent[rootU] = rootV;
        }
    }

    private boolean isCyclic(int[] edge) {
        int rootU = find(edge[0]);
        int rootV = find(edge[1]);

        if (rootU == rootV) {
            return true; // Adding this edge creates a cycle
        }

        union(edge);
        return false;
    }
}