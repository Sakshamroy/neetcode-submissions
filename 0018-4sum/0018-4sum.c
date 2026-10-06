#include <stdlib.h>

// Comparator for qsort
static int compare(const void* a, const void* b) {
    long diff = (long)*(int*)a - (long)*(int*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort to enable two-pointer approach and duplicate skipping
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 64;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicate elements for the first position
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Pruning optimizations
        if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        if ((long)nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicate elements for the second position
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Pruning optimizations
            if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if ((long)nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                // Use long to prevent integer overflow
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                    // Skip duplicates for the third and fourth elements
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}