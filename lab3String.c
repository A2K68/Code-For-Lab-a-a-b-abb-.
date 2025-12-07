#include <stdio.h>
#include <string.h>

// Function to check if string is "a"
int isA(char *str) {
    return (strlen(str) == 1 && str[0] == 'a');
}

// Function to check if string matches "a*b+"
int isAstarBplus(char *str) {
    int len = strlen(str);
    int i = 0;

    // Count 'a's (zero or more)
    for (i = 0; i < len && str[i] == 'a'; i++)
        ;

    // Count 'b's (one or more)
    int j = i;
    for ( ; j < len && str[j] == 'b'; j++)
        ;

    // Check that there is at least one 'b' and nothing else
    if ((j - i) >= 1 && j == len)
        return 1;
    else
        return 0;
}

// Function to check if string is "abb"
int isABB(char *str) {
    return (strcmp(str, "abb") == 0);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // REMOVE newline from fgets
    input[strcspn(input, "\n")] = '\0';

    if (isA(input))
        printf("String '%s' is accepted under pattern 'a'\n", input);
    else if (isAstarBplus(input))
        printf("String '%s' is accepted under pattern 'a*b+'\n", input);
    else if (isABB(input))
        printf("String '%s' is accepted under pattern 'abb'\n", input);
    else
        printf("String '%s' is rejected.\n", input);

    return 0;
}
