//WAP to implement regular expressions that accepts string containing aba as substring.


#include <stdio.h>
#include <regex.h>

#define MAX_MATCHES 1
#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE];
    regex_t regex;
    int reti;
    char msgbuf[BUFFER_SIZE];

    reti = regcomp(&regex, ".*aba.*", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    printf("Enter the string: ");
    scanf("%s", input);

    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti) {
        printf("String contains 'aba' as a substring\n");
    } else if (reti == REG_NOMATCH) {
        printf("String does not contain 'aba' as a substring\n");
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 1;
    }

    regfree(&regex);

    return 0;
}
