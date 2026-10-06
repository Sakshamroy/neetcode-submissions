#include <string.h>
#include <stdlib.h>

static int expandAroundCenter(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length is (right - 1) - (left + 1) + 1
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) return s;

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindromes (single character center)
        int len1 = expandAroundCenter(s, i, i, n);
        // Even length palindromes (between two characters)
        int len2 = expandAroundCenter(s, i, i + 1, n);

        int len = len1 > len2 ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    // Allocate buffer for null-terminated result substring
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}