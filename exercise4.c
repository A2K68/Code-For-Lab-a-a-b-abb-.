#include <stdio.h>
#include <string.h>

// Function to check if string matches (a/b)(a/b)
int isAorBAorB(char *str) {
    // Must be exactly 2 characters long
    if (strlen(str) != 2)
        return 0;

    // Both characters must be 'a' or 'b'
    if ((str[0] == 'a' || str[0] == 'b') &&
        (str[1] == 'a' || str[1] == 'b'))
        return 1;

    return 0;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAorBAorB(input))
        printf("String '%s' is accepted under pattern (a/b)(a/b)\n", input);
    else
        printf("String '%s' is rejected.\n", input);

    return 0;
}
