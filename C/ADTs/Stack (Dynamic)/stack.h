#define StackSize 100

typedef struct stack tStack;

tStack *createStack(int elementSize);
void destroy(tStack *p);
int isFull(tStack *p);
int isEmpty(tStack *p);
int push(tStack *p, void *elem);
int pop(tStack *p, void *elem);
int top(tStack *p, void *elem);
