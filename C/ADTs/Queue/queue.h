#define QueueSize 10

typedef int elem;

typedef struct s_queue queue;

queue *createQueue();
int isEmpty(queue *q);
int isFull(queue *q);
int insert(queue *q, elem x);
int removeElement(queue *q, elem *x);
void destroy(queue *q);