//first program: WAP to implement DFA that accepts the string starting with aa .

#include <stdio.h>

int isAccepted(char *input) {
    int currentState = 0;
    int i = 0;

    while (input[i] != '\0') {
        char symbol = input[i];
        if (currentState == 0) {
            if (symbol == 'a') {
                currentState = 1;
            } else {
                return 0;
            }
        } else if (currentState == 1) {
            if (symbol == 'a') {
                currentState = 2;
            } else {
                return 0;
            }
        } else {
        }
        i++;
    }

    if (currentState == 2) {
        return 1;
    } else {
        return 0;
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
