/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

// 키 값을 insertion 했을 때 가지고 있는 노드에 대한 구조체 listNode
typedef struct Node {
	int key;
	struct Node* link;
} listNode;

// linked-list를 가르키고 있는 구조체 headNode
typedef struct Head {
	struct Node* first;
} headNode;


/* 함수 리스트 */
// initialize하는 함수
headNode* initialize(headNode* h);
// 할당된 노드들을 해제하는 함수
int freeList(headNode* h);
// 첫번째에 노드를 insertion 하는 함수
int insertFirst(headNode* h, int key);
// 노드 하나를 insertion 하는 함수
int insertNode(headNode* h, int key);
// 마지막에 노드를 insertion 하는 함수
int insertLast(headNode* h, int key);

// 첫번째 노드를 삭제하는 함수
int deleteFirst(headNode* h);
// 특정 노드를 삭제하는 함수
int deleteNode(headNode* h, int key);
// 마지막 노드를 삭제하는 함수
int deleteLast(headNode* h);
// 리스트를 역순으로 재배치하는 함수
int invertList(headNode* h);

// 리스트를 출력하는 함수
void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	printf("[----- 서범교 2021039042 -----]\n\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {
	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	// linked-list가 구성이 되어있는 경우 메모리 해제
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
	// 삽입할 노드 생성
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if(node == NULL)
		return -1;
	// 삽입할 노드의 key값 설정
	node->key = key;
	// 삽입할 노드의 link를 NULL로 설정
	node->link = NULL;
	// 리스트가 비어있거나 첫 번째 노드의 키가 입력받은 키보다 큰 경우
	if(h -> first == NULL || h -> first -> key > key){
		// 새 노드의 링크를 첫 번째 노드로 설정
		node->link = h->first; 
		// 헤드 노드를 새 노드로 설정
        h->first = node; 
	} else { // 첫 번째 노드의 키가 입력받은 키보다 작은 경우
		// 첫 번째 노드를 임시 변수에 저장
		listNode* temp = h -> first;
		// 입력된 키보다 큰키를 가진 노드를 찾을 때까지 반복
		while(temp -> link != NULL && temp -> link -> key < key){
			temp = temp -> link;
		}
		// 새 노드의 링크를 temp의 다음 노드로 설정
		node -> link = temp -> link;
		// temp의 링크를 새 노드로 설정
		temp -> link = node;
	}
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	// 삽입할 노드 생성
	listNode* node = (listNode*)malloc(sizeof(listNode));
	// 메모리 할당 실패시 -1 반환하여 오류 처리
	if(node == NULL)
		return -1;
	// 삽입할 노드의 key값 설정
	node->key = key;
	// 삽입할 노드의 link를 NULL로 설정
	node->link = NULL;

	// 리스트가 비어있는 경우
	if (h->first == NULL){
		// 삽입할 노드를 첫 번째 노드로 설정
		h -> first = node;
	} else {
		// 첫 번째 노드를 임시 변수에 저장
		listNode * temp = h -> first;
		// 마지막 노드를 찾을 때까지 반복
		while (temp -> link != NULL){
			temp = temp -> link;
		}
		// 마지막 노드의 link를 삽입할 노드로 설정
		temp -> link = node;
 	} 
	return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	// 리스트가 비어있으면 -1 반환하여 오류 처리
	if(h->first == NULL) return -1;
	// 첫 번째 노드를 임시 변수에 저장
	listNode* temp = h->first;
	// 첫 번째 노드를 두번째 노드로 변경
	h->first = temp->link;
	// 첫 번째 노드 메모리 해제
	free(temp);
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	// 리스트가 비어있으면 -1 반환하여 오류 처리
	if (h->first == NULL) return -1;
	// 삭제할 키가 첫번째 노드인 경우 deleteFirst 함수 호출
    if (h->first->key == key) return deleteFirst(h);

	// 첫 번째 노드를 임시 변수에 저장
    listNode* temp = h->first;
	// 삭제할 key값을 가진 노드를 찾을 때까지 반복
    while (temp->link != NULL && temp->link->key != key) {
        temp = temp->link;
    }
	// 찾지 못하면 -1 반환하여 오류 처리
    if (temp->link == NULL) return -1;

	// 삭제할 노드를 임시 변수에 저장
    listNode* delNode = temp->link;
	// 삭제할 노드의 이전 노드와 다음 노드를 연결
    temp->link = delNode->link;
	// 삭제할 노드 메모리 해제
    free(delNode);
	return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	// 리스트가 비어있으면 -1 반환하여 오류 처리
	if (h->first == NULL) return -1;
	// 리스트에 노드가 하나만 있는 경우 deleteFirst 함수 호출
    if (h->first->link == NULL) return deleteFirst(h);

	// 첫 번째 노드를 임시 변수에 저장
    listNode* temp = h->first;
	// 마지막 노드를 찾을 때까지 반복
    while (temp->link->link != NULL) {
        temp = temp->link;
    } // while 문이 끝나면 temp는 마지막에서 두번째 노드를 가리킴

	// 마지막 노드 메모리 해제
    free(temp->link);
	// 마지막에서 두 번째 노드의 링크를 NULL로 변경
    temp->link = NULL;
	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	if (h->first == NULL || h->first->link == NULL) return -1;

    listNode* prev = NULL;
    listNode* current = h->first;
    listNode* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    h->first = prev;
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}