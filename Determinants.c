#include <stdio.h>
#include "bca_math.h"

int main(){
    int num1 = 2; // order 2x2
    int num2 = 3; // order 3x3
    int a, b, c;
    int mat1[2][2] = {{4,6}, {2,5}};
    int mat2[3][3] = {{2, 0, 5}, {3 ,1, 1}, {1, 4, 6}};
    int mat3[3][3] = {{3, 5, -7}, {4, 1, -12}, {2, 9, -3}};
    int mat4[3][3] = {0};
    int constant[3] = {13, 6, 20};

    int x = determinant(num1, mat1);
    int y = determinant(num2, mat2);
    printf("%d\n", x);
    printf("%d\n", y);

    cramers_rule(&a, &b, &c, mat3, constant);
    printf("A: %d B: %d C: %d\n", a, b, c);

    addMat(3, mat2, mat3, mat4);
    traverseMat(3, mat4);
}

