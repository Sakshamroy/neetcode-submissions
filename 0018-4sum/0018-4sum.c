int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target,
              int* returnSize, int** returnColumnSizes) {

    int capacity = 1000;

    int **ans = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {

        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            // Skip duplicates
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];

                if (sum == target) {

                    ans[*returnSize] = malloc(4 * sizeof(int));

                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[left];
                    ans[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers
                    left++;
                    right--;

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return ans;
}
