#include <stdio.h>
#include <stdlib.h>


int maxAndMin(int matrix[], int matrixSize, int * returnedMin){
    int max = matrix[0];
    int min = matrix[0];

    int i;
    for (i = 0; i < matrixSize; i++){
        if (matrix[i] > max){
            max = matrix[i];
        } else if(matrix[i] < min){
            min = matrix[i];
        }
    }

    * returnedMin = min;
    return max;
}

float averageVal(int matrix[], int matrixSize, int ignored, int * returnedAmountOfIgnored, int * returnedStatus){
    float iterSum = 0;
    int amountOfIgnored = 0;
    int i;
    for (i = 0; i < matrixSize; i++){
        if (matrix[i] == ignored){
            amountOfIgnored++;
        }
    }
    matrixSize -= amountOfIgnored;
    * returnedAmountOfIgnored = amountOfIgnored;
    if (matrixSize != 0){
        for (i = 0; i < matrixSize; i++){
        if (matrix[i] != ignored){
            iterSum += matrix[i];
        }
    }
    } else {
        * returnedStatus = 0;
        return 0;
    }

    * returnedStatus = 1;
    return iterSum / matrixSize;
}

int main(){
    int matr[5] = {23, 1, 7, 127, 8};
    int matrixMin, matrixMax;
    float matrixAverageMaxIgnored, matrixAverageMinIgnored;

    matrixMax = maxAndMin(matr, sizeof(matr) / sizeof(int), &matrixMin);
    printf("local max: %d, local min: %d\n", matrixMax, matrixMin);
    matrixAverageMaxIgnored = averageVal(matr, sizeof(matr) / sizeof(int), matrixMax);
    matrixAverageMinIgnored = averageVal(matr, sizeof(matr) / sizeof(int), matrixMin);
    printf("average value, max ignored: %f\n", matrixAverageMaxIgnored);
    printf("average value, min ignored: %f\n", matrixAverageMinIgnored);

    return 0;
}