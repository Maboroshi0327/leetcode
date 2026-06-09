#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);

    if (len % 2 != 0)
        return false;

    char *stack = malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                top++;
                stack[top] = s[i];
                continue;
        }

        if (top < 0) {
            free(stack);
            return false;
        }

        char pop;
        pop = stack[top];
        top--;

        bool valid = (pop == '(' && s[i] == ')') ||
                     (pop == '[' && s[i] == ']') ||
                     (pop == '{' && s[i] == '}');
        if (!valid) {
            free(stack);
            return false;
        }
    }

    free(stack);
    return top == -1;
}
