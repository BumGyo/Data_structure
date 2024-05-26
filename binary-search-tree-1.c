/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

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
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}

// ������ȸ(LVR) : ���� �ڽ� ��� -> �θ� ��� -> ������ �ڽ� ��� ������ �湮
void inorderTraversal(Node* ptr) {
	// ptr�� NULL�� �ƴ� ������ �ݺ�
	if(ptr) {
		// ���� �ڽ� ���� �̵�
		inorderTraversal(ptr->left);
		// ���� ��� ���
		printf("[%d] ", ptr->key);
		// ������ �ڽ� ���� �̵�
		inorderTraversal(ptr->right);
	}
}

// ������ȸ(VLR) : �θ� ��� -> ���� �ڽ� ��� -> ������ �ڽ� ��� ������ �湮
void preorderTraversal(Node* ptr) {
	if(ptr) {
		// ���� ��� ���
		printf("[%d] ", ptr->key);
		// ���� �ڽ� ���� �̵�
		preorderTraversal(ptr->left);
		// ������ �ڽ� ���� �̵�
		preorderTraversal(ptr->right);
	}
}

// ������ȸ(LRV) : ���� �ڽ� ��� -> ������ �ڽ� ��� -> �θ� ��� ������ �湮
void postorderTraversal(Node* ptr) {
	if(ptr) {
		// ���� �ڽ� ���� �̵�
		postorderTraversal(ptr->left);
		// ������ �ڽ� ���� �̵�
		postorderTraversal(ptr->right);
		// ���� ��� ���
		printf("[%d] ", ptr->key);
	}
}

// ���ο� ��� �����ϴ� �Լ�
Node* createNode(int key) {
	// ���� �޸� �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	// ��� �ʱ�ȭ
	newNode->key = key;
	// ����, ������ �ڽ� ��� NULL�� �ʱ�ȭ
	newNode->left = NULL;
	newNode->right = NULL;
	// ������ ��� ��ȯ
	return newNode;
}

// ��尪�� �߰��ϴ� �Լ�
int insert(Node* head, int key) {
	// Ʈ���� ��Ʈ ��带 ����Ű�� ������ ptr
	Node* ptr = head;
	// ���ο� ��� newNode ����
	Node* newNode = createNode(key);
	
	// ��Ʈ ��尡 NULL�� ���
	if(head == NULL){
		// ���ο� ��带 ��Ʈ ���� ����
		head = newNode;
		return 1;
	}
	// ���� ����
	while(1) {
		// ��Ʈ ����� Ű���� ���ο� ����� Ű������ ū ���
        if(ptr->key > key) {
			// ���� �ڽ� ��尡 NULL�� �ƴ� ���
            if(ptr->left != NULL) {
				// ���� �ڽ� ���� �̵�
                ptr = ptr->left;
            } else {
				// ���� �ڽ��� ���ο� ���� ����
                ptr->left = newNode;
				// �ݺ��� ����
                break;
            }
        } else if(ptr->key < key) {
            if(ptr->right != NULL) {
                // ������ �ڽ� ���� �̵�
				ptr = ptr->right;
            } else {
				// ������ �ڽ��� ���ο� ���� ����
                ptr->right = newNode;
				// �ݺ��� ����
                break;
            }
        } else {
			// Ű���� �ߺ��Ǹ� ����
            return 0;
        }
    }
    return 1;
}

int deleteLeafNode(Node* head, int key)
{

}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}


int freeBST(Node* head)
{

}





