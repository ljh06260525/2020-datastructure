
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000

typedef struct { // 큐 타입
	int  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void push(QueueType *q, int item)
{
	if (is_full(q)) 
		error("큐가 포화상태입니다");
	
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

// 삭제 함수
int pop(QueueType *q)
{
	if (is_empty(q))	return -1;

	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

// 저장 되어 있는 정수의 개수 출력 함수
int size(QueueType *q) {
	int count = abs(q->rear - q->front);	
	return count;
}

// front 출력 함수
void front(QueueType *q) {
	if (is_empty(q))
		printf("-1\n");

	else {
		int front_print = (q->front + 1) % MAX_QUEUE_SIZE;
		printf("%d\n", q->data[front_print]);
	}
}

//back 출력함수
void back(QueueType *q) {
	if (is_empty(q))
		printf("-1\n");
	
	else
		printf("%d\n", q->data[q->rear]);
}

int main(void)
{
	QueueType queue;
	int N = 0;
	int element = NULL;
	char command[100] = { 0 };
	init_queue(&queue);

	while (!is_full(&queue))
	{
		
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%s", command);

			if (strcmp(command, "push") == 0) {
				scanf("%d", &element);
				push(&queue, element);
			}

			else {
				if (strcmp(command, "pop") == 0) {
					printf("%d\n", pop(&queue));
				}
				else if (strcmp(command, "size") == 0) {
					printf("%d\n", size(&queue));
				}
				else if (strcmp(command, "empty") == 0) {
					printf("%d\n", is_empty(&queue));
				}
				else if (strcmp(command, "front") == 0) {
					front(&queue);
				}
				else if (strcmp(command, "back") == 0) {
					back(&queue);
				}
				else return 0;
			}
		}
		break;
	}
}