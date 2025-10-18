#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[256] = {0}; // Initialize all char counts to 0
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Iterate through the string until the '\0' is found
    while (str[i] != '\0') {
        freq[(int)str[i]]++;
        i++;
    }

    // Print the count of each character
    printf("\nCharacter counts:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }

    return 0;
}
