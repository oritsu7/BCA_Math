#include <stdio.h>
#include "bca_math.h"

int main(){
    int num1 = 2; // order 2x2
    int num2 = 3; // order 3x3
    int mat1[2][2] = {{4,6}, {2,5}};
    int mat2[3][3] = {{2, 0, 5}, {3 ,1, 1}, {1, 4, 6}};

    int x = determinant(num1, mat1);
    int y = determinant(num2, mat2);
    printf("%d\n", x);
    printf("%d", y);
}