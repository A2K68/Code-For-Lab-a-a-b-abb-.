#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[200];
    char token[50];
    int i = 0, j;
    
    printf("Enter C code: ");
    gets(input);
    
    printf("\nLEXEME\t\tTOKEN\n");
    printf("------\t\t-----\n");
    
    while (input[i] != '\0') {
        // Skip spaces
        if (input[i] == ' ') {
            i++;
            continue;
        }
        
        // Operators
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || 
            input[i] == '/' || input[i] == '=') {
            printf("%c\t\tOperator\n", input[i]);
            i++;
        }
        // Special symbols
        else if (input[i] == '(' || input[i] == ')' || input[i] == '{' || 
                 input[i] == '}' || input[i] == ';' || input[i] == ',') {
            printf("%c\t\tSymbol\n", input[i]);
            i++;
        }
        // Numbers
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("%s\t\tNumber\n", token);
        }
        // Keywords or Identifiers
        else if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            
            if (isKeyword(token))
                printf("%s\t\tKeyword\n", token);
            else
                printf("%s\t\tIdentifier\n", token);
        }
        else {
            i++;
        }
    }
    
    return 0;
}