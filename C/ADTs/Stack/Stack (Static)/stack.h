#define StackSize 100

typedef int element;

typedef struct stack tStack;

tStack *createStack();
void destroy(tStack *p);
int isFull(tStack *p);
int isEmpty(tStack *p);
int push(tStack *p, element elem);
int pop(tStack *p, element *elem);
int top(tStack *p, element *elem);