// WAP to implement DFA that accepts the string starting with aa.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int transition(int state, char input)
{
    if (state == 0 && input == 'a')
    {
        return 1;
    }
    else if (state == 1 && input == 'a')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

bool is_accepted(char *string)
{
    int current_state = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        current_state = transition(current_state, string[i]);
        if (current_state == -1)
        {
            return false;
        }
    }
    return current_state == 2;
}

int main()
{
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    if (is_accepted(input_string))
    {
        printf("'%s' is accepted\n", input_string);
    }
    else
    {
        printf("'%s' is not accepted\n", input_string);
    }

    return 0;
}
