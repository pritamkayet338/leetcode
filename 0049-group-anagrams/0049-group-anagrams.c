#include <stdlib.h>
#include <string.h>

typedef struct {
    char* str;
    char* key;
} Item;

int compare49(const void* a, const void* b) {
    Item* x = (Item*)a;
    Item* y = (Item*)b;

    return strcmp(x->key, y->key);
}

int compareChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize,
                      int** returnColumnSizes) {

    Item* items = malloc(strsSize * sizeof(Item));

    // Create sorted key for every string
    for (int i = 0; i < strsSize; i++) {

        int len = strlen(strs[i]);

        items[i].str = strs[i];

        items[i].key = malloc((len + 1) * sizeof(char));

        strcpy(items[i].key, strs[i]);

        qsort(items[i].key, len, sizeof(char), compareChar);
    }

    // Sort strings by their keys
    qsort(items, strsSize, sizeof(Item), compare49);

    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    *returnSize = 0;

    int i = 0;

    while (i < strsSize) {

        int j = i + 1;

        while (j < strsSize &&
               strcmp(items[i].key, items[j].key) == 0) {
            j++;
        }

        int count = j - i;

        result[*returnSize] = malloc(count * sizeof(char*));

        for (int k = 0; k < count; k++)
            result[*returnSize][k] = items[i + k].str;

        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;

        i = j;
    }

    for (i = 0; i < strsSize; i++)
        free(items[i].key);

    free(items);

    return result;
}