
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char password[256];

    const char *common_passwords[] = {
        "password123456789",
        "qwerty1234567890",
        "12345678901234567",
        "admin1234567890",
        "abcdefghijklmnop"
    };

    size_t common_count =
        sizeof(common_passwords) / sizeof(common_passwords[0]);

    printf("Enter password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading password.\n");
        return 1;
    }

    // Check whether the input exceeds the buffer
    if (strchr(password, '\n') == NULL) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        printf("Rejected: Password is too long.\n");
        return 1;
    }

    // Remove newline
    password[strcspn(password, "\n")] = '\0';

    size_t length = strlen(password);

    // Check length
    if (length <= 16) {
        printf("Rejected: Password must exceed 16 characters.\n");
        return 1;
    }

    // Check special symbols
    int has_symbol = 0;

    for (size_t i = 0; i < length; i++) {
        if (ispunct((unsigned char)password[i])) {
            has_symbol = 1;
            break;
        }
    }

    if (!has_symbol) {
        printf("Rejected: Password must contain a special symbol.\n");
        return 1;
    }

    // Check common passwords
    for (size_t i = 0; i < common_count; i++) {
        if (strcmp(password, common_passwords[i]) == 0) {
            printf("Rejected: Common password detected.\n");
            return 1;
        }
    }

    printf("Password meets all requirements.\n");

    return 0;
}
