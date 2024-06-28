/**
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

// char�� ��Ī���� element ����
typedef char element;
// ���� ť QueueType ����ü ����
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void) {
	QueueType *cQ = createQueue();
	element data;
	char command;

	printf("[----- ������ 2021039042 -----]\n\n");
	// 'q'�� �Է��ϱ� ������ �ݺ�
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}
	}while(command != 'q' && command != 'Q');

	return 1;
}

QueueType *createQueue() {
	// ť ����ü ������ cQ ����
	QueueType *cQ;
	// cq�� �����޸� �Ҵ�
	cQ = (QueueType *)malloc(sizeof(QueueType));
	// front�� rear�� 0���� �ʱ�ȭ
	cQ->front = 0;
	cQ->rear = 0;
	// ť�� �ʱⰪ�� �������� ����(�����Ⱚ ���� �� ����)
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) {
        cQ->queue[i] = ' ';
    }
	// cQ ��ȯ
	return cQ;
}

// ���� �޸� ���� �Լ�
int freeQueue(QueueType *cQ) {
    // cQ�� NULL�̸� 1�� ��ȯ
	if(cQ == NULL) return 1;
	// �ƴϸ� �����޸� ���� �� 1�� ��ȯ
    free(cQ);
    return 1;
}

// ť�� ���� �ִ� �Լ�
element getElement() {
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(QueueType *cQ) {
	// front�� rear�� ������ ����ִ� ������
	if(cQ->front == cQ->rear){
		return 1;
	} else {
		return 0;
	}
}

/* complete the function */
// ť�� ���� ���ִ��� Ȯ���ϴ� �Լ�
int isFull(QueueType *cQ) {
	// rear�� ������ front�̸� ���� �� ���¶� 1�� ����
	if((cQ->rear + 1) % MAX_QUEUE_SIZE == cQ->front){
		return 1;
	} else {
		return 0;
	}
}

/* complete the function */
// ť�� �����͸� �ִ� �Լ�
void enQueue(QueueType *cQ, element item) {
	// ť�� ���� ���ִ��� isFull() �Լ��� Ȯ��
	if(isFull(cQ)){
		printf("ť�� ���� ������\n");
		return;
	}
	// rear�� ���� ��ġ�� �̵��ϰ� �����͸� ����
	cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
	cQ->queue[cQ->rear] = item;
}

/* complete the function */
// ť���� �����͸� �����ϴ� �Լ�(���� ���� ���� ����X)
void deQueue(QueueType *cQ, element *item) {
	// ť�� ����ִ��� isEmpty() �Լ��� Ȯ��
	if(isEmpty(cQ)){
		printf("ť�� �������\n");
		return;
	}
	// front�� ���� ��ġ�� �̵��ϰ� �����͸� ����
	cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
}

// ���� ť�� element�� ���� �ִ��� �˷��ִ� �Լ�
void printQ(QueueType *cQ) {
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}

// ���� ť�� index�� ���� element�� �˷��ְ� front�� rear�� �˷��ִ� �Լ�
void debugQ(QueueType *cQ) {

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}