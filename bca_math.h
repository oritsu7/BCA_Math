#include<stdio.h>

int determinant(int n, int mat[n][n]) { // ? is there an another way to do this? (mat[n][n])
    if (n == 2) {
        return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }
    
    int det = 0;
    for (int col = 0; col < n; col++) {
        // Create a minor matrix
        int minor[n-1][n-1]; // ! expression must have a constant value problem
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

void cramers_rule(int* x, int* y, int* z, int mat[3][3], int *constant){
    int det = determinant(3, mat);
    if(det == 0)
        return;   
    int mat_x[3][3]; 
    int mat_y[3][3];
    int mat_z[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mat_x[i][j] = mat[i][j];
            mat_y[i][j] = mat[i][j];
            mat_z[i][j] = mat[i][j];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==0)
                mat_x[j][i] = constant[j];
            else if(i == 1)
                mat_y[j][i] = constant[j];
            else
                mat_z[j][i] = constant[j];             
        }
    }

    int det_x = determinant(3, mat_x);
    int det_y = determinant(3, mat_y);
    int det_z = determinant(3, mat_z);

    *x = det_x/det;
    *y = det_y/det;
    *z = det_z/det;
}

// addition of matrix 
void addMat(int n, int mat1[n][n], int mat2[n][n], int mat3[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
// print matrix
void traverseMat(int n, int mat[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }    
}