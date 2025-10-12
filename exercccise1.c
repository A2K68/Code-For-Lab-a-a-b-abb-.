#include <stdio.h>
#include <string.h>

// Function to check if string matches (a/b)*abb
int isAorBStarAbb(char *str) {
    int len = strlen(str);

    // Must be at least 3 characters long for "abb"
    if (len < 3)
        return 0;

    // Check if the last three characters are 'a', 'b', 'b'
    if (str[len - 3] == 'a' && str[len - 2] == 'b' && str[len - 1] == 'b') {
        // Check that all previous characters (if any) are either 'a' or 'b'
        for (int i = 0; i < len - 3; i++) {
            if (str[i] != 'a' && str[i] != 'b')
                return 0;  // Invalid character found
        }
        return 1;  // Matches pattern (a/b)*abb
    }

    return 0;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAorBStarAbb(input))
        printf("String '%s' is accepted under pattern (a/b)*abb\n", input);
    else
        printf("String '%s' is rejected.\n", input);

    return 0;
}
