#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
int n;
int m = 0;
int p, i = 0, j = 0;
char a[10][10];
char f[10];

// Function prototypes
void follow(char c);
void first(char c);

int main() {
    int i, z;
    char c, ch;

    // Input Phase
    printf("Enter the number of productions:\n");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s%c", a[i], &ch); // Reads production into a[i] and newline into ch
    }

    // Processing Phase (in a loop)
    do {
        m = 0;      // Reset index for set calculation
        
        printf("Enter the element whose First & Follow is to be found: ");
        scanf("%c", &c);

        // Calculate and print First set
        first(c);
        printf("First(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        // Reset and calculate Follow set
        strcpy(f, " ");   // Clear the f array
        m = 0;           // Reset index
        
        follow(c);
        printf("Follow(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        printf("Continue (0/1)? ");
        scanf("%d%c", &z, &ch);
    } while (z == 1);

    return 0;
}

// Function to compute the First set of a given non-terminal
void first(char c) {
    int k;
    
    // If c is terminal, add to First set directly
    if (!isupper(c)) {
        f[m++] = c;
        return;
    }

    // For non-terminals, check all productions
    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {  // If left side matches c
            if (a[k][2] == '$') {  // If production → ε
                follow(a[k][0]);    // Add Follow set
            }
            else if (islower(a[k][2])) {  // If production → terminal
                f[m++] = a[k][2];         // Add terminal to First set
            }
            else {  // If production → non-terminal
                first(a[k][2]);    // Recursively find First of that non-terminal
            }
        }
    }
}

// Function to compute the Follow set of a given non-terminal
void follow(char c) {
    // Add $ to Follow set of start symbol
    if (a[0][0] == c) {
        f[m++] = '$';
    }

    // Check all productions
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {  // If c is found in right side
                if (a[i][j + 1] != '\0') {  // If something follows c
                    first(a[i][j + 1]);     // Add First of next symbol
                }
                // If c is at end and not left side of its own production
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]);  // Add Follow of left side non-terminal
                }
            }
        }
    }
}
