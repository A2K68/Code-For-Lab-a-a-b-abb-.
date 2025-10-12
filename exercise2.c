
#include <stdio.h>
#include <string.h>

// Function to check if string matches (a/b)
int isAorB(char *str) {
    return (strlen(str) == 1 && (str[0] == 'a' || str[0] == 'b'));
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAorB(input))
        printf("String '%s' is accepted under pattern (a/b)\n", input);
    else
        printf("String '%s' is rejected.\n", input);

    return 0;
}
