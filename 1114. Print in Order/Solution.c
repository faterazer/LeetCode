#include <semaphore.h>
#include <stdlib.h>

typedef struct
{
    // User defined data may be declared here.
    sem_t firstDone;
    sem_t secondDone;
} Foo;

Foo *fooCreate()
{
    Foo *obj = (Foo *)malloc(sizeof(Foo));
    // Initialize user defined data here.
    sem_init(&obj->firstDone, 0, 0);
    sem_init(&obj->secondDone, 0, 0);
    return obj;
}

void first(Foo *obj)
{
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->firstDone);
}

void second(Foo *obj)
{
    sem_wait(&obj->firstDone);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->secondDone);
}

void third(Foo *obj)
{
    sem_wait(&obj->secondDone);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo *obj)
{
    // User defined data may be cleaned up here.
    sem_destroy(&obj->firstDone);
    sem_destroy(&obj->secondDone);
    free(obj);
    obj = NULL;
}
