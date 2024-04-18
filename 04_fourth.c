
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *input) {
    int currentState = 0;
    int i = 0;
    bool foundConsecutiveOnes = false;

    while (input[i] != '\0') {
        char symbol = input[i];
        if (currentState == 0) {
            if (symbol == '0') {
                currentState = 0;
            } else if (symbol == '1') {
                currentState = 1;
            }
        } else if (currentState == 1) {
            if (symbol == '0') {
                currentState = 0;
                foundConsecutiveOnes = false;
            } else if (symbol == '1') {
                currentState = 2;
                foundConsecutiveOnes = true;
            }
        } else if (currentState == 2) {
            if (symbol == '0' || symbol == '1') {
                currentState = 2;
            }
        }
        i++;
    }

    if (foundConsecutiveOnes) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}
