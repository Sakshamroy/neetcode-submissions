#include <stdlib.h>
#include <string.h>

static void backtrack(int open, int close, int max, char* current, int index, 
                      char*** result, int* returnSize, int* capacity) {
    // When the string reaches length 2 * n, we found a valid combination
    if (index == 2 * max) {
        current[index] = '\0';
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (char**)realloc(*result, (*capacity) * sizeof(char*));
        }
        (*result)[*returnSize] = (char*)malloc((2 * max + 1) * sizeof(char));
        strcpy((*result)[*returnSize], current);
        (*returnSize)++;
        return;
    }

    // Can add an opening bracket if we haven't reached n
    if (open < max) {
        current[index] = '(';
        backtrack(open + 1, close, max, current, index + 1, result, returnSize, capacity);
    }

    // Can add a closing bracket if it doesn't exceed open brackets
    if (close < open) {
        current[index] = ')';
        backtrack(open, close + 1, max, current, index + 1, result, returnSize, capacity);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int capacity = 16;
    char** result = (char**)malloc(capacity * sizeof(char*));
    
    // Buffer for building combinations of length 2 * n + 1 for null terminator
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    backtrack(0, 0, n, current, 0, &result, returnSize, &capacity);

    free(current);
    return result;
}