#include <stdio.h>
#include <string.h>

// Function to check if string matches aa(a+b)*bb
int isAaAplusBStarBb(char *str) {
    int len = strlen(str);

    // Must be at least 4 characters long: "aa" + "bb"
    if (len < 4)
        return 0;

    // Check prefix "aa"
    if (str[0] != 'a' || str[1] != 'a')
        return 0;

    // Check suffix "bb"
    if (str[len - 2] != 'b' || str[len - 1] != 'b')
        return 0;

    // Check middle part (a+b)* — can be empty, but must contain only 'a' or 'b'
    for (int i = 2; i < len - 2; i++) {
        if (str[i] != 'a' && str[i] != 'b')
            return 0;  // invalid character found
    }

    return 1;  // all conditions satisfied
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAaAplusBStarBb(input))
        printf("String '%s' is accepted under pattern aa(a+b)*bb\n", input);
    else
        printf("String '%s' is rejected.\n", input);

    return 0;
}
