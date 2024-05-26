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

	printf("[----- 서범교 2021039042 -----]\n");

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

// 중위순회(LVR) : 왼쪽 자식 노드 -> 부모 노드 -> 오른쪽 자식 노드 순으로 방문
void inorderTraversal(Node* ptr) {
    if (ptr) {
        inorderTraversal(ptr->left);	// 왼쪽 자식 노드로 이동
        printf("[%d] ", ptr->key);		// 현재 노드 출력
        inorderTraversal(ptr->right);	// 오른쪽 자식 노드로 이동
    }
}

// 전위순회(VLR) : 부모 노드 -> 왼쪽 자식 노드 -> 오른쪽 자식 노드 순으로 방문
void preorderTraversal(Node* ptr) {
    if (ptr) {
        printf("[%d] ", ptr->key);		// 현재 노드 출력
        preorderTraversal(ptr->left);	// 왼쪽 자식 노드로 이동
        preorderTraversal(ptr->right);	// 오른쪽 자식 노드로 이동
    }
}

// 후위순회(LRV) : 왼쪽 자식 노드 -> 오른쪽 자식 노드 -> 부모 노드 순으로 방문
void postorderTraversal(Node* ptr) {
    if (ptr) {
        postorderTraversal(ptr->left);		// 왼쪽 자식 노드로 이동
        postorderTraversal(ptr->right);		// 오른쪽 자식 노드로 이동
        printf("[%d] ", ptr->key);			// 현재 노드 출력
    }
}

// 노드값을 추가하는 함수
int insert(Node* head, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));	// 새로운 노드 newNode 생성
    newNode->key = key;
    newNode->left = newNode->right = NULL;

	// 루트 노드가 NULL인 경우
    if (head->left == NULL) {
        head->left = newNode;	// 루트 노드에 새로운 노드로 설정
        return 1;
    }

    Node* parent = NULL;
    Node* ptr = head->left;

	// 현제 노드가 NULL이 아닐 때까지 반복
    while (ptr != NULL) {
		// 키값이 중복되는 경우
        if (key == ptr->key) {
            free(newNode);		// 새로운 노드 메모리 해제
            return 0;
        }
		// 부모 노드 설정
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

// 리프 노드를 삭제하는 함수
int deleteLeafNode(Node* head, int key) {
    if (head->left == NULL)		
        return 0;

    Node* parent = head;
    Node* ptr = head->left;

	// 현제 노드가 NULL이 아닐 때까지 반복
    while (ptr != NULL) {
        if (key == ptr->key) {
            if (ptr->left == NULL && ptr->right == NULL) {
                if (parent->left == ptr)
                    parent->left = NULL;	// 부모 노드의 왼쪽 노드를 NULL로 설정
                else
                    parent->right = NULL;	// 부모 노드의 오른쪽 노드를 NULL로 설정
                free(ptr);			// 현재 노드 메모리 해제
                return 1;
            } else {
				printf("the node [%d] is not a leaf\n", key);	// 리프 노드가 아닌 경우
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

// Recursive 방식으로 search하는 함수
Node* searchRecursive(Node* ptr, int key) {
	// 현재 노드가 NULL이거나 키값이 같은 경우
    if (ptr == NULL || ptr->key == key)
        return ptr;

    if (key < ptr->key)	// 키값이 현재 노드의 키값보다 작은 경우
        return searchRecursive(ptr->left, key);
    else			// 키값이 현재 노드의 키값보다 큰 경우
        return searchRecursive(ptr->right, key);
}

// Iterative 방식으로 search하는 함수
Node* searchIterative(Node* head, int key) {
    Node* ptr = head->left;
	// 현제 노드가 NULL이 아닐 때까지 반복
    while (ptr != NULL) {
        if (key == ptr->key)	// 키값이 현재 노드의 키값과 같은 경우
            return ptr;
        if (key < ptr->key)		// 키값이 현재 노드의 키값보다 작은 경우
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return NULL;
}

// 트리에 할당된 메모리를 해제하는 함수
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