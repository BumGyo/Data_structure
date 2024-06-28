/**
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

// char를 별칭으로 element 정의
typedef char element;
// 원형 큐 QueueType 구조체 정의
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

	printf("[----- 서범교 2021039042 -----]\n\n");
	// 'q'를 입력하기 전까지 반복
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
	// 큐 구조체 포인터 cQ 선언
	QueueType *cQ;
	// cq에 동적메모리 할당
	cQ = (QueueType *)malloc(sizeof(QueueType));
	// front와 rear를 0으로 초기화
	cQ->front = 0;
	cQ->rear = 0;
	// 큐의 초기값을 공백으로 설정(쓰레기값 들어가는 것 방지)
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) {
        cQ->queue[i] = ' ';
    }
	// cQ 반환
	return cQ;
}

// 동적 메모리 해제 함수
int freeQueue(QueueType *cQ) {
    // cQ가 NULL이면 1을 반환
	if(cQ == NULL) return 1;
	// 아니면 동적메모리 해제 후 1을 반환
    free(cQ);
    return 1;
}

// 큐에 값을 넣는 함수
element getElement() {
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
// 큐가 비어있는지 확인하는 함수
int isEmpty(QueueType *cQ) {
	// front와 rear가 같으면 비어있는 상태임
	if(cQ->front == cQ->rear){
		return 1;
	} else {
		return 0;
	}
}

/* complete the function */
// 큐가 가득 차있는지 확인하는 함수
int isFull(QueueType *cQ) {
	// rear의 다음이 front이면 가득 찬 상태라서 1을 리턴
	if((cQ->rear + 1) % MAX_QUEUE_SIZE == cQ->front){
		return 1;
	} else {
		return 0;
	}
}

/* complete the function */
// 큐에 데이터를 넣는 함수
void enQueue(QueueType *cQ, element item) {
	// 큐가 가득 차있는지 isFull() 함수로 확인
	if(isFull(cQ)){
		printf("큐가 가득 차있음\n");
		return;
	}
	// rear를 다음 위치로 이동하고 데이터를 넣음
	cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
	cQ->queue[cQ->rear] = item;
}

/* complete the function */
// 큐에서 데이터를 삭제하는 함수(실제 값에 대한 삭제X)
void deQueue(QueueType *cQ, element *item) {
	// 큐가 비어있는지 isEmpty() 함수로 확인
	if(isEmpty(cQ)){
		printf("큐가 비어있음\n");
		return;
	}
	// front를 다음 위치로 이동하고 데이터를 삭제
	cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
}

// 현재 큐의 element가 뭐가 있는지 알려주는 함수
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

// 현재 큐의 index에 따른 element를 알려주고 front와 rear를 알려주는 함수
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