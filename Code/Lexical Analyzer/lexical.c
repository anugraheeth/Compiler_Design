#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    
    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1; // It's a keyword
        }
    }
    
    return 0; // Not a keyword
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%", specialch[] = ".,;[]{}", num[] = "1234567890", buf[10];
    FILE *fp;
    
    fp = fopen("text.txt", "r");
    
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }
    
    int j = 0, k = 0;
    
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch) || ch == '\n') {
            if (j != 0) {
                buffer[j] = '\0';
                if (isKeyword(buffer) == 1) {
                    printf("%s is keyword\n", buffer);
                } else {
                    printf("%s is identifier\n", buffer);
                }
                j = 0;
            }
            if (k != 0) {
                buf[k] = '\0';
                printf("%s is constant\n", buf);
                k = 0;
            }
        } else if (strchr(operators, ch) != NULL) {
            printf("%c is operator\n", ch);
        } else if (strchr(specialch, ch) != NULL) {
            printf("%c is special character\n", ch);
        } else if (isalpha(ch)) {
            buffer[j++] = ch;
        } else if (isdigit(ch)) {
            buf[k++] = ch;
        }
    }
    
    fclose(fp);
    return 0;
}
