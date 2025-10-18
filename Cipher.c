#include <stdio.h>
#include <string.h>

void process_data(char *text, const char *key) {
    size_t text_len = strlen(text);
    size_t key_len = strlen(key);
    for (size_t i = 0; i < text_len; i++) {
        text[i] ^= key[i % key_len];
    }
}

int main() {
    char data[] = "A simple demonstration of a reversible cipher.";
    const char secret_key[] = "GEMINI";

    printf("Original:  %s\n", data);
    process_data(data, secret_key);
    printf("Processed: %s\n", data);
    process_data(data, secret_key);
    printf("Restored:  %s\n", data);

    return 0;
}
