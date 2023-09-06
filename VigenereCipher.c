#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenere encryption
void vigenereEncrypt(char plaintext[], char key[]) {
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);
    char encryptedText[plaintextLen + 1];

    for (int i = 0, j = 0; i < plaintextLen; i++) {
        char plainChar = plaintext[i];
        if (isalpha(plainChar)) {
            char keyChar = key[j % keyLen];

            if (islower(plainChar)) {
                encryptedText[i] = 'a' + (plainChar - 'a' + keyChar - 'a') % 26;
            } else {
                encryptedText[i] = 'A' + (plainChar - 'A' + keyChar - 'a') % 26;
            }

            j++;
        } else {
            encryptedText[i] = plainChar;
        }
    }

    encryptedText[plaintextLen] = '\0';

    printf("Encrypted Text: %s\n", encryptedText);
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from the input strings
    strtok(plaintext, "\n");
    strtok(key, "\n");

    vigenereEncrypt(plaintext, key);

    return 0;
}
