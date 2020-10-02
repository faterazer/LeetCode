#include <stdlib.h>

typedef int T;

typedef struct LinkedNode
{
    T data;
    struct LinkedNode *next;
} LinkedNode;

typedef struct
{
    LinkedNode *head;
    LinkedNode *rear;
    size_t size;
} LinkedList;

LinkedList* createLinkedList(void)
{
    LinkedList *new = (LinkedList*)malloc(sizeof(LinkedList));
    new->head = (LinkedNode*)malloc(sizeof(LinkedNode));
    new->head->next = NULL;
    new->rear = new->head;
    new->size = 0;
    return new;
}

void freeLinkedList(LinkedList *list)
{
    while (list->head) {
        LinkedNode *p = list->head;
        list->head = list->head->next;
        free(p);
    }
    list->rear = NULL;
    list->size = 0;
}

size_t linkedListSize(LinkedList *list)
{
    return list->size;
}

T linkedListFront(LinkedList *list)
{
    return list->head->next->data;
}

T LinkedListPopFront(LinkedList *list)
{
    LinkedNode *p = list->head->next;
    list->head->next = list->head->next->next;
    T ret = p->data;
    free(p);
    list->size -= 1;
    return ret;
}

void linkedListPushBack(LinkedList *list, T e)
{
    LinkedNode *p = (LinkedNode*)malloc(sizeof(LinkedNode));
    p->data = e;
    p->next = NULL;
    list->rear->next = p;
    list->rear = p;
    list->size += 1;
}

typedef struct
{
    LinkedList *data;
} Queue;

Queue* CreateQueue(void)
{
    Queue *new = (Queue*)malloc(sizeof(Queue));
    new->data = createLinkedList();
    return new;
}

void freeQueue(Queue *queue)
{
    freeLinkedList(queue->data);
}

T queueFront(Queue *queue)
{
    return linkedListFront(queue->data);
}

void queuePush(Queue *queue, T e)
{
    linkedListPushBack(queue->data, e);
}

int queuePop(Queue *queue)
{
    return LinkedListPopFront(queue->data);
}

size_t queueSize(Queue *queue)
{
    return linkedListSize(queue->data);
}

typedef struct
{
    Queue *queue;
} RecentCounter;

RecentCounter* recentCounterCreate()
{
    RecentCounter *counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->queue = CreateQueue();
    return counter;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    queuePush(obj->queue, t);
    while (t - queueFront(obj->queue) > 3000)
        queuePop(obj->queue);
    return queueSize(obj->queue);
}

void recentCounterFree(RecentCounter *obj)
{
    freeQueue(obj->queue);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
