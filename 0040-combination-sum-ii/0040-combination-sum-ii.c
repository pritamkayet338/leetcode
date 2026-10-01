#include <stdlib.h>

int compare40(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack40(int* candidates, int n, int target,
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

    for (int i = start; i < n; i++) {

        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];

        backtrack40(candidates, n, target - candidates[i],
                    i + 1, path, pathSize + 1,
                    result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize,
                      int target, int* returnSize,
                      int** returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), compare40);

    int capacity = 10000;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    int* path = malloc(candidatesSize * sizeof(int));

    backtrack40(candidates, candidatesSize, target,
                0, path, 0,
                &result, returnSize, returnColumnSizes);

    free(path);

    return result;
}