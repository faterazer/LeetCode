#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char *address)
{
    int size = strlen(address), idx = 0;
    char *ret = (char*)malloc(sizeof(char) * (size + 7));
    for (int i = 0; i < size; i++) {
        if (address[i] == '.') {
            strcpy(ret + idx, "[.]");
            idx += 3;
        }
        else
            ret[idx++] = address[i];
    }
    ret[idx] = '\0';
    return ret;
}
