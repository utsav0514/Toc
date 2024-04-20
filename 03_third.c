// WAP to implement DFA that accepts the string containing aba as a substring.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *input)
{
    int currentState = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        char symbol = input[i];
        if (currentState == 0)
        {
            if (symbol == 'a')
            {
                currentState = 1;
            }
        }
        else if (currentState == 1)
        {
            if (symbol == 'b')
            {
                currentState = 2;
            }
            else if (symbol == 'a')
            {
                currentState = 1;
            }
            else
            {
                currentState = 0;
            }
        }
        else if (currentState == 2)
        {
            if (symbol == 'a')
            {
                currentState = 3;
            }
            else if (symbol == 'b')
            {
                currentState = 2;
            }
            else
            {
                currentState = 0;
            }
        }
        else if (currentState == 3)
        {
            if (symbol == 'a')
            {
                currentState = 3;
                return true; // Accept if 'aba' is found
            }
            else if (symbol == 'b')
            {
                currentState = 2;
            }
            else
            {
                currentState = 0;
            }
        }
        i++;
    }

    return false; // If 'aba' is not found
}

int main()
{
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);

    if (isAccepted(input))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Not Accepted\n");
    }

    return 0;
}
