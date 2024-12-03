#include <stdio.h>
#include "bca_math.h"

int main(){
    int q = 2; // order 2x2
    int r = 3; // order 3x3
    int a, b, c;
    int mat1[2][2] = {{4,6}, {2,5}};
    int mat2[3][3] = {{2, 0, 5}, {3 ,1, 1}, {1, 4, 6}};
    int mat3[3][3] = {{3, 5, -7}, {4, 1, -12}, {2, 9, -3}};
    int mat4[3][3] = {0};
    int constant[3] = {13, 6, 20};
    int sym[3][3] = {{2, 3, 4}, {3, 1, -2}, {4, -2, 0}};

    int x = determinant(q, mat1);
    int y = determinant(r, mat2);
    printf("%d\n", x);
    printf("%d\n", y);

    cramers_rule(&a, &b, &c, mat3, constant);
    printf("A: %d B: %d C: %d\n", a, b, c);

    addMat(r, mat2, mat3, mat4);
    traverseMat(r, mat4);

    trans_second(r, mat3, mat4);
    traverseMat(r, mat4);
    transpose(r, mat2);
    
    traverseMat(r, mat2);
    if(is_symmetric(r, sym))
        printf("Matrix is symmetric");
    else
        printf("Matrix is not symmetric");
    

    int mat5[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int mat6[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int res[2][2]; 

    mulMat(2, 3, mat5, 3, 2, mat6, res);
    traverseMat(2, res);

}

