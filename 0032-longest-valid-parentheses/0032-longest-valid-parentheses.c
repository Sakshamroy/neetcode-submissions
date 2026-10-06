#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int left = 0, right = 0;
    int maxLen = 0;

    // Left-to-right pass
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int currentLen = 2 * right;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else if (right > left) {
            left = right = 0;
        }
    }

    // Right-to-left pass to handle cases with extra '(' (e.g., "(()")
    left = right = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int currentLen = 2 * left;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else if (left > right) {
            left = right = 0;
        }
    }

    return maxLen;
}