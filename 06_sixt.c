#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *input) {
    int i = 0;

    if (input[0] != '1' || input[1] != '1') {
        return false;
    }

    while (input[i] != '\0') {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
        i++;
    }

    return true;
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
