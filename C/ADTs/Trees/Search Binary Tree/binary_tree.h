#define true 1
#define false 0

typedef int boolean;
typedef int TYPEKEY;

typedef struct node_s node;

node *initialize();
node *createNewNode(TYPEKEY key);
node *insert(node *root, node *newNode);
node *search(TYPEKEY key, node *root);
int getSize(node *root);
void showTree(node *root);
node *searchNode(node *root, TYPEKEY key, node **parent);
node *removeNode(node *root, TYPEKEY key);