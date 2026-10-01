#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int* result = malloc(rows * cols * sizeof(int));

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    *returnSize = 0;

    while (top <= bottom && left <= right) {

        // Left → Right
        for (int j = left; j <= right; j++)
            result[(*returnSize)++] = matrix[top][j];

        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++)
            result[(*returnSize)++] = matrix[i][right];

        right--;

        // Right → Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[(*returnSize)++] = matrix[bottom][j];

            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[(*returnSize)++] = matrix[i][left];

            left++;
        }
    }

    return result;
}