#include <stdlib.h>

void backtrack39(int* candidates, int n, int target,
                 int start, int* path, int pathSize,
                 int*** result, int* returnSize,
                 int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    if (target < 0)
        return;

    for (int i = start; i < n; i++) {
        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        backtrack39(candidates, n, target - candidates[i],
                    i, path, pathSize + 1,
                    result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {

    int capacity = 10000;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    int* path = malloc(target * sizeof(int));

    backtrack39(candidates, candidatesSize, target,
                0, path, 0,
                &result, returnSize, returnColumnSizes);

    free(path);

    return result;
}