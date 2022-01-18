
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000

typedef struct { // ť Ÿ��
	int  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ �Լ�
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void push(QueueType *q, int item)
{
	if (is_full(q)) 
		error("ť�� ��ȭ�����Դϴ�");
	
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

// ���� �Լ�
int pop(QueueType *q)
{
	if (is_empty(q))	return -1;

	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

// ���� �Ǿ� �ִ� ������ ���� ��� �Լ�
int size(QueueType *q) {
	int count = abs(q->rear - q->front);	
	return count;
}

// front ��� �Լ�
void front(QueueType *q) {
	if (is_empty(q))
		printf("-1\n");

	else {
		int front_print = (q->front + 1) % MAX_QUEUE_SIZE;
		printf("%d\n", q->data[front_print]);
	}
}

//back ����Լ�
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