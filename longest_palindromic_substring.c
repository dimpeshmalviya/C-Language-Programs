#include <stdio.h>
#include <string.h>

int expand(char *s, int l, int r) {
    while (l >= 0 && r < strlen(s) && s[l] == s[r]) l--, r++;
    return r - l - 1;
}

int main() {
    char s[] = "babad";
    int start = 0, maxLen = 0, n = strlen(s);
    for (int i = 0; i < n; i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = len1 > len2 ? len1 : len2;
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }
    char res[maxLen + 1];
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    printf("%s\n", res);
}