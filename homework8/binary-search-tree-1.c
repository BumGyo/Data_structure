#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

int initializeBST(Node** h);
void inorderTraversal(Node* ptr);      /* recursive inorder traversal */
void preorderTraversal(Node* ptr);     /* recursive preorder traversal */
void postorderTraversal(Node* ptr);    /* recursive postorder traversal */
int insert(Node* head, int key);       /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head);               /* free all memories allocated to the tree */

int main()
{
    char command;
    int key;
    Node* head = NULL;
    Node* ptr = NULL;    /* temp */

	printf("[----- ������ 2021039042 -----]\n");

    do{
        printf("\n\n");
        printf("----------------------------------------------------------------\n");
        printf("                   Binary Search Tree #1                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize BST       = z                                       \n");
        printf(" Insert Node          = n      Delete Node                  = d \n");
        printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
        printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
        printf(" Postorder Traversal  = t      Quit                         = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            initializeBST(&head);
            break;
        case 'q': case 'Q':
            freeBST(head);
            break;
        case 'n': case 'N':
            printf("Your Key = ");
            scanf("%d", &key);
            insert(head, key);
            break;
        case 'd': case 'D':
            printf("Your Key = ");
            scanf("%d", &key);
            deleteLeafNode(head, key);
            break;
        case 'f': case 'F':
            printf("Your Key = ");
            scanf("%d", &key);
            ptr = searchIterative(head, key);
            if(ptr != NULL)
                printf("\n node [%d] found at %p\n", ptr->key, ptr);
            else
                printf("\n Cannot find the node [%d]\n", key);
            break;
        case 's': case 'S':
            printf("Your Key = ");
            scanf("%d", &key);
            ptr = searchRecursive(head->left, key);
            if(ptr != NULL)
                printf("\n node [%d] found at %p\n", ptr->key, ptr);
            else
                printf("\n Cannot find the node [%d]\n", key);
            break;

        case 'i': case 'I':
            inorderTraversal(head->left);
            break;
        case 'p': case 'P':
            preorderTraversal(head->left);
            break;
        case 't': case 'T':
            postorderTraversal(head->left);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

int initializeBST(Node** h) {
    /* if the tree is not empty, then remove all allocated nodes from the tree*/
    if(*h != NULL)
        freeBST(*h);

    /* create a head node */
    *h = (Node*)malloc(sizeof(Node));
    (*h)->left = NULL;    /* root */
    (*h)->right = *h;
    (*h)->key = -9999;
    return 1;
}

// ������ȸ(LVR) : ���� �ڽ� ��� -> �θ� ��� -> ������ �ڽ� ��� ������ �湮
void inorderTraversal(Node* ptr) {
    if (ptr) {
        inorderTraversal(ptr->left);	// ���� �ڽ� ���� �̵�
        printf("[%d] ", ptr->key);		// ���� ��� ���
        inorderTraversal(ptr->right);	// ������ �ڽ� ���� �̵�
    }
}

// ������ȸ(VLR) : �θ� ��� -> ���� �ڽ� ��� -> ������ �ڽ� ��� ������ �湮
void preorderTraversal(Node* ptr) {
    if (ptr) {
        printf("[%d] ", ptr->key);		// ���� ��� ���
        preorderTraversal(ptr->left);	// ���� �ڽ� ���� �̵�
        preorderTraversal(ptr->right);	// ������ �ڽ� ���� �̵�
    }
}

// ������ȸ(LRV) : ���� �ڽ� ��� -> ������ �ڽ� ��� -> �θ� ��� ������ �湮
void postorderTraversal(Node* ptr) {
    if (ptr) {
        postorderTraversal(ptr->left);		// ���� �ڽ� ���� �̵�
        postorderTraversal(ptr->right);		// ������ �ڽ� ���� �̵�
        printf("[%d] ", ptr->key);			// ���� ��� ���
    }
}

// ��尪�� �߰��ϴ� �Լ�
int insert(Node* head, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));	// ���ο� ��� newNode ����
    newNode->key = key;
    newNode->left = newNode->right = NULL;

	// ��Ʈ ��尡 NULL�� ���
    if (head->left == NULL) {
        head->left = newNode;	// ��Ʈ ��忡 ���ο� ���� ����
        return 1;
    }

    Node* parent = NULL;
    Node* ptr = head->left;

	// ���� ��尡 NULL�� �ƴ� ������ �ݺ�
    while (ptr != NULL) {
		// Ű���� �ߺ��Ǵ� ���
        if (key == ptr->key) {
            free(newNode);		// ���ο� ��� �޸� ����
            return 0;
        }
		// �θ� ��� ����
        parent = ptr;
        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return 1;
}

// ���� ��带 �����ϴ� �Լ�
int deleteLeafNode(Node* head, int key) {
    if (head->left == NULL)		
        return 0;

    Node* parent = head;
    Node* ptr = head->left;

	// ���� ��尡 NULL�� �ƴ� ������ �ݺ�
    while (ptr != NULL) {
        if (key == ptr->key) {
            if (ptr->left == NULL && ptr->right == NULL) {
                if (parent->left == ptr)
                    parent->left = NULL;	// �θ� ����� ���� ��带 NULL�� ����
                else
                    parent->right = NULL;	// �θ� ����� ������ ��带 NULL�� ����
                free(ptr);			// ���� ��� �޸� ����
                return 1;
            } else {
				printf("the node [%d] is not a leaf\n", key);	// ���� ��尡 �ƴ� ���
                return 0;
            }
        }

        parent = ptr;	
        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    return 0;
}

// Recursive ������� search�ϴ� �Լ�
Node* searchRecursive(Node* ptr, int key) {
	// ���� ��尡 NULL�̰ų� Ű���� ���� ���
    if (ptr == NULL || ptr->key == key)
        return ptr;

    if (key < ptr->key)	// Ű���� ���� ����� Ű������ ���� ���
        return searchRecursive(ptr->left, key);
    else			// Ű���� ���� ����� Ű������ ū ���
        return searchRecursive(ptr->right, key);
}

// Iterative ������� search�ϴ� �Լ�
Node* searchIterative(Node* head, int key) {
    Node* ptr = head->left;
	// ���� ��尡 NULL�� �ƴ� ������ �ݺ�
    while (ptr != NULL) {
        if (key == ptr->key)	// Ű���� ���� ����� Ű���� ���� ���
            return ptr;
        if (key < ptr->key)		// Ű���� ���� ����� Ű������ ���� ���
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return NULL;
}

// Ʈ���� �Ҵ�� �޸𸮸� �����ϴ� �Լ�
int freeBST(Node* head) {
    if (head == NULL)
        return 0;

    if (head->left != head) {
        freeBST(head->left);
        freeBST(head->right);
    }

    free(head);
    return 1;
}