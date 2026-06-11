#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int inStack[MAX_SIZE];
    int outStack[MAX_SIZE];
    int inTop;
    int outTop;
} MyQueue;

MyQueue *myQueueCreate() {
    MyQueue *myQueue = malloc(sizeof(MyQueue));
    myQueue->inTop = -1;
    myQueue->outTop = -1;
    return myQueue;
}

void myQueuePush(MyQueue *obj, int x) {
    obj->inTop++;
    obj->inStack[obj->inTop] = x;
}

void moveStack(MyQueue *obj) {
    if (obj->outTop == -1) {
        while (obj->inTop != -1) {
            obj->outTop++;
            obj->outStack[obj->outTop] = obj->inStack[obj->inTop];
            obj->inTop--;
        }
    }
}

int myQueuePop(MyQueue *obj) {
    moveStack(obj);

    if (obj->outTop == -1)
        return 0;

    int pop = obj->outStack[obj->outTop];
    obj->outTop--;

    return pop;
}

int myQueuePeek(MyQueue *obj) {
    moveStack(obj);

    if (obj->outTop == -1)
        return 0;

    return obj->outStack[obj->outTop];
}

bool myQueueEmpty(MyQueue *obj) {
    return obj->inTop == -1 && obj->outTop == -1;
}

void myQueueFree(MyQueue *obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
