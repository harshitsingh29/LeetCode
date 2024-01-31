class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int m = n;
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m-k; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = temp;
            }
            k++;
        }
        for (int col = 0; col < n; col++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                int temp = matrix[start][col];
                matrix[start][col] = matrix[end][col];
                matrix[end][col] = temp;
                start++;
                end--;
            }
        }
        return;
    }
}