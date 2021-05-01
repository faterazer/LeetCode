#include <stdlib.h>

typedef struct
{
    char **vs;
    int size;
    int ptr;
} OrderedStream;

OrderedStream* orderedStreamCreate(int n)
{
    OrderedStream *p = (OrderedStream*)malloc(sizeof(OrderedStream));
    p->vs = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
        p->vs[i] = NULL;
    p->size = n;
    p->ptr = 0;
    return p;
}

char** orderedStreamInsert(OrderedStream *obj, int idKey, char *value, int *retSize)
{
    int i = idKey - 1;
    char **res;
    obj->vs[i] = value;
    *retSize = 0;
    if (i == obj->ptr) {
        while (obj->ptr < obj->size && obj->vs[obj->ptr]) {
            obj->ptr++;
            (*retSize)++;
        }
        res = (char**)malloc(sizeof(char*) * (*retSize));
        for (int j = i; j < obj->ptr; j++)
            res[j - i] = obj->vs[j];
    }
    return res;
}

void orderedStreamFree(OrderedStream *obj)
{
    for (int i = 0; i < obj->size; i++) {
        free(obj->vs[i]);
        obj->vs[i] = NULL;
    }
    free(obj->vs);
    free(obj);
    obj->vs = NULL;
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/
