// Function to calculate the determinant of a matrix
int determinant(int n, int mat[n][n]) {
    if (n == 2) {
        return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }
    
    int det = 0;
    for (int col = 0; col < n; col++) {
        // Create a minor matrix
        int minor[n-1][n-1];
        for (int i = 1; i < n; i++) { // Skip the first row
            int minor_col = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue; // Skip the current column
                minor[i-1][minor_col] = mat[i][j];
                minor_col++;
            }
        }
        
        // Recursive call to determinant function
        int cofactor = (col % 2 == 0 ? 1 : -1) * mat[0][col];
        det += cofactor * determinant(n-1, minor);
    }
    return det;
}