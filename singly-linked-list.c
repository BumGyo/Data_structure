/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

// Ű ���� insertion ���� �� ������ �ִ� ��忡 ���� ����ü listNode
typedef struct Node {
	int key;
	struct Node* link;
} listNode;

// linked-list�� ����Ű�� �ִ� ����ü headNode
typedef struct Head {
	struct Node* first;
} headNode;


/* �Լ� ����Ʈ */
// initialize�ϴ� �Լ�
headNode* initialize(headNode* h);
// �Ҵ�� ������ �����ϴ� �Լ�
int freeList(headNode* h);
// ù��°�� ��带 insertion �ϴ� �Լ�
int insertFirst(headNode* h, int key);
// ��� �ϳ��� insertion �ϴ� �Լ�
int insertNode(headNode* h, int key);
// �������� ��带 insertion �ϴ� �Լ�
int insertLast(headNode* h, int key);

// ù��° ��带 �����ϴ� �Լ�
int deleteFirst(headNode* h);
// Ư�� ��带 �����ϴ� �Լ�
int deleteNode(headNode* h, int key);
// ������ ��带 �����ϴ� �Լ�
int deleteLast(headNode* h);
// ����Ʈ�� �������� ���ġ�ϴ� �Լ�
int invertList(headNode* h);

// ����Ʈ�� ����ϴ� �Լ�
void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	printf("[----- ������ 2021039042 -----]\n\n");

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
	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	// linked-list�� ������ �Ǿ��ִ� ��� �޸� ����
	if(h != NULL)
		freeList(h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
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
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
	// ������ ��� ����
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if(node == NULL)
		return -1;
	// ������ ����� key�� ����
	node->key = key;
	// ������ ����� link�� NULL�� ����
	node->link = NULL;
	// ����Ʈ�� ����ְų� ù ��° ����� Ű�� �Է¹��� Ű���� ū ���
	if(h -> first == NULL || h -> first -> key > key){
		// �� ����� ��ũ�� ù ��° ���� ����
		node->link = h->first; 
		// ��� ��带 �� ���� ����
        h->first = node; 
	} else { // ù ��° ����� Ű�� �Է¹��� Ű���� ���� ���
		// ù ��° ��带 �ӽ� ������ ����
		listNode* temp = h -> first;
		// �Էµ� Ű���� ūŰ�� ���� ��带 ã�� ������ �ݺ�
		while(temp -> link != NULL && temp -> link -> key < key){
			temp = temp -> link;
		}
		// �� ����� ��ũ�� temp�� ���� ���� ����
		node -> link = temp -> link;
		// temp�� ��ũ�� �� ���� ����
		temp -> link = node;
	}
	return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
	// ������ ��� ����
	listNode* node = (listNode*)malloc(sizeof(listNode));
	// �޸� �Ҵ� ���н� -1 ��ȯ�Ͽ� ���� ó��
	if(node == NULL)
		return -1;
	// ������ ����� key�� ����
	node->key = key;
	// ������ ����� link�� NULL�� ����
	node->link = NULL;

	// ����Ʈ�� ����ִ� ���
	if (h->first == NULL){
		// ������ ��带 ù ��° ���� ����
		h -> first = node;
	} else {
		// ù ��° ��带 �ӽ� ������ ����
		listNode * temp = h -> first;
		// ������ ��带 ã�� ������ �ݺ�
		while (temp -> link != NULL){
			temp = temp -> link;
		}
		// ������ ����� link�� ������ ���� ����
		temp -> link = node;
 	} 
	return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
	// ����Ʈ�� ��������� -1 ��ȯ�Ͽ� ���� ó��
	if(h->first == NULL) return -1;
	// ù ��° ��带 �ӽ� ������ ����
	listNode* temp = h->first;
	// ù ��° ��带 �ι�° ���� ����
	h->first = temp->link;
	// ù ��° ��� �޸� ����
	free(temp);
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
	// ����Ʈ�� ��������� -1 ��ȯ�Ͽ� ���� ó��
	if (h->first == NULL) return -1;
	// ������ Ű�� ù��° ����� ��� deleteFirst �Լ� ȣ��
    if (h->first->key == key) return deleteFirst(h);

	// ù ��° ��带 �ӽ� ������ ����
    listNode* temp = h->first;
	// ������ key���� ���� ��带 ã�� ������ �ݺ�
    while (temp->link != NULL && temp->link->key != key) {
        temp = temp->link;
    }
	// ã�� ���ϸ� -1 ��ȯ�Ͽ� ���� ó��
    if (temp->link == NULL) return -1;

	// ������ ��带 �ӽ� ������ ����
    listNode* delNode = temp->link;
	// ������ ����� ���� ���� ���� ��带 ����
    temp->link = delNode->link;
	// ������ ��� �޸� ����
    free(delNode);
	return 0;
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
	// ����Ʈ�� ��������� -1 ��ȯ�Ͽ� ���� ó��
	if (h->first == NULL) return -1;
	// ����Ʈ�� ��尡 �ϳ��� �ִ� ��� deleteFirst �Լ� ȣ��
    if (h->first->link == NULL) return deleteFirst(h);

	// ù ��° ��带 �ӽ� ������ ����
    listNode* temp = h->first;
	// ������ ��带 ã�� ������ �ݺ�
    while (temp->link->link != NULL) {
        temp = temp->link;
    } // while ���� ������ temp�� ���������� �ι�° ��带 ����Ŵ

	// ������ ��� �޸� ����
    free(temp->link);
	// ���������� �� ��° ����� ��ũ�� NULL�� ����
    temp->link = NULL;
	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
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