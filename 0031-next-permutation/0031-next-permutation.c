static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    // 1. Find the first decreasing element from the right
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // 2. If such an element is found, find the element just larger than nums[i] to its right
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    // 3. Reverse the suffix starting after index i to make it the smallest possible order
    reverse(nums, i + 1, numsSize - 1);
}