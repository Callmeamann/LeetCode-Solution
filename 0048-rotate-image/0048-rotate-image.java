class Solution {
    private void transpose(int[][] matrix, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i != j) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    }

    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // Method 1:
        // transpose(matrix, n);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n / 2; j++) {
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[i][n - j - 1];
        //         matrix[i][n - j - 1] = temp;
        //     }
        // }

        // Method 2:
        for (int i = 0; i < n / 2; i++) {
            int[] temp = matrix[i];
            matrix[i] = matrix[n - i - 1];
            matrix[n - i - 1] = temp;
        }
        transpose(matrix, n);
    }
}
