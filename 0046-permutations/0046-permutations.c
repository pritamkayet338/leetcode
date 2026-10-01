#include <stdlib.h>

void permute46(int* nums, int n, int* used,
               int* path, int pathSize,
               int*** result, int* returnSize,
               int** returnColumnSizes) {

    if (pathSize == n) {

        (*result)[*returnSize] = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            (*result)[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;

        return;
    }

    for (int i = 0; i < n; i++) {

        if (used[i])
            continue;

        used[i] = 1;
        path[pathSize] = nums[i];

        permute46(nums, n, used, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);

        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize,
              int** returnColumnSizes) {

    int total = 1;

    for (int i = 1; i <= numsSize; i++)
        total *= i;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    *returnSize = 0;

    int* used = calloc(numsSize, sizeof(int));
    int* path = malloc(numsSize * sizeof(int));

    permute46(nums, numsSize, used, path, 0,
              &result, returnSize, returnColumnSizes);

    free(used);
    free(path);

    return result;
}