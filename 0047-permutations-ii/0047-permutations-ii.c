#include <stdlib.h>

int compare47(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void permute47(int* nums, int n, int* used,
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

        // Skip duplicate values
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        path[pathSize] = nums[i];

        permute47(nums, n, used, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize,
                    int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare47);

    int total = 1;

    for (int i = 1; i <= numsSize; i++)
        total *= i;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    *returnSize = 0;

    int* used = calloc(numsSize, sizeof(int));
    int* path = malloc(numsSize * sizeof(int));

    permute47(nums, numsSize, used, path, 0,
              &result, returnSize, returnColumnSizes);

    free(used);
    free(path);

    return result;
}