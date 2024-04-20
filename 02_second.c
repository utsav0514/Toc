#include <stdio.h>
#include <stdbool.h>

typedef enum {
    STATE_Q0,
    STATE_Q1,
    STATE_Q2
} State;

State transition(State current_state, char input_char) {
    switch (current_state) {
        case STATE_Q0:
            if (input_char == '0')
                return STATE_Q0;
            else if (input_char == '1')
                return STATE_Q1;
            break;
        case STATE_Q1:
            if (input_char == '0')
                return STATE_Q0;
            else if (input_char == '1')
                return STATE_Q2;
            break;
        case STATE_Q2:
            return STATE_Q2;
    }
    return current_state;
}

bool dfa_accepts_ending_11(const char *string) {
    State current_state = STATE_Q0;
    for (int i = 0; string[i] != '\0'; i++) {
        current_state = transition(current_state, string[i]);
    }
    return current_state == STATE_Q2;
}

int main() {
    char input_string[100];
    printf("Enter a binary string: ");
    scanf("%99s", input_string);
    
    bool result = dfa_accepts_ending_11(input_string);
    printf("String: %s -> Accepted: %s\n", input_string, result ? "Yes" : "No");
    
    return 0;
}
