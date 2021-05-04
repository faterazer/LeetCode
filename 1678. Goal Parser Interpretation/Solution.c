#include <stdlib.h>
#include <string.h>

char* interpret(char *command)
{
    int n = strlen(command), len = 0;
    char *res = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        if (command[i] == 'G')
            res[len++] = 'G';
        else if (command[i] == ')') {
            if (command[i - 1] == '(')
                res[len++] = 'o';
            else {
                res[len++] = 'a';
                res[len++] = 'l';
            }
        }
    }
    res[len] = '\0';
    return res;
}
