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

// 중위순회(LVR) : 왼쪽 자식 노드 -> 부모 노드 -> 오른쪽 자식 노드 순으로 방문
void inorderTraversal(Node* ptr) {
	// ptr이 NULL이 아닐 때까지 반복
	if(ptr) {
		// 왼쪽 자식 노드로 이동
		inorderTraversal(ptr->left);
		// 현재 노드 출력
		printf("[%d] ", ptr->key);
		// 오른쪽 자식 노드로 이동
		inorderTraversal(ptr->right);
	}
}

// 전위순회(VLR) : 부모 노드 -> 왼쪽 자식 노드 -> 오른쪽 자식 노드 순으로 방문
void preorderTraversal(Node* ptr) {
	if(ptr) {
		// 현재 노드 출력
		printf("[%d] ", ptr->key);
		// 왼쪽 자식 노드로 이동
		preorderTraversal(ptr->left);
		// 오른쪽 자식 노드로 이동
		preorderTraversal(ptr->right);
	}
}

// 후위순회(LRV) : 왼쪽 자식 노드 -> 오른쪽 자식 노드 -> 부모 노드 순으로 방문
void postorderTraversal(Node* ptr) {
	if(ptr) {
		// 왼쪽 자식 노드로 이동
		postorderTraversal(ptr->left);
		// 오른쪽 자식 노드로 이동
		postorderTraversal(ptr->right);
		// 현재 노드 출력
		printf("[%d] ", ptr->key);
	}
}

// 새로운 노드 생성하는 함수
Node* createNode(int key) {
	// 동적 메모리 할당
	Node* newNode = (Node*)malloc(sizeof(Node));
	// 노드 초기화
	newNode->key = key;
	// 왼쪽, 오른쪽 자식 노드 NULL로 초기화
	newNode->left = NULL;
	newNode->right = NULL;
	// 생성한 노드 반환
	return newNode;
}

// 노드값을 추가하는 함수
int insert(Node* head, int key) {
	// 트리의 루트 노드를 가리키는 포인터 ptr
	Node* ptr = head;
	// 새로운 노드 newNode 생성
	Node* newNode = createNode(key);
	
	// 루트 노드가 NULL인 경우
	if(head == NULL){
		// 새로운 노드를 루트 노드로 설정
		head = newNode;
		return 1;
	}
	// 무한 루프
	while(1) {
		// 루트 노드의 키값이 새로운 노드의 키값보다 큰 경우
        if(ptr->key > key) {
			// 왼쪽 자식 노드가 NULL이 아닌 경우
            if(ptr->left != NULL) {
				// 왼쪽 자식 노드로 이동
                ptr = ptr->left;
            } else {
				// 왼쪽 자식을 새로운 노드로 설정
                ptr->left = newNode;
				// 반복문 종료
                break;
            }
        } else if(ptr->key < key) {
            if(ptr->right != NULL) {
                // 오른쪽 자식 노드로 이동
				ptr = ptr->right;
            } else {
				// 오른쪽 자식을 새로운 노드로 설정
                ptr->right = newNode;
				// 반복문 종료
                break;
            }
        } else {
			// 키값이 중복되면 종료
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





