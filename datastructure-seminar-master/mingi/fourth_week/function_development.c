#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _QueueNode {                 // ���� ����Ʈ������ ��� ����
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct {                            // ť�� front�� rear�� ����ü�� ����
    QueueNode *front, *rear;
    int size;
} LinkedQueueType;

void init_queue(LinkedQueueType **q) {      // ť�� �ʱ�ȭ(���� ������ ���)
    (*q)->front = (*q)->rear = NULL;
    (*q)->size = 0;
}

int is_empty(LinkedQueueType *q) {          // ���� ����Ʈ�� ����ִ� �� Ȯ��
    return q->rear == NULL;
}

void enqueue(LinkedQueueType **q, element item) {                   // ť ��� ���� ����
    QueueNode *newnode = (QueueNode *) malloc(sizeof(QueueNode));
    if (newnode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    } else {
        newnode->data = item;
        newnode->link = NULL;
        if (is_empty(*q)) {
            (*q)->rear = newnode;
            (*q)->front = newnode;
        }
        (*q)->rear->link = newnode;
        (*q)->rear = newnode;
    }
    (*q)->size++;
}

element dequeue(LinkedQueueType **q) {                              // ť ��� ���� ����
    QueueNode *removed = (*q)->front;
    element item = removed->data;
    if (is_empty(*q)) {
        fprintf(stderr, "ť ���� ����\n");
        exit(1);
    } else {
        (*q)->size--;
        (*q)->front = removed->link;
        if ((*q)->front == NULL)
            (*q)->rear = NULL;
        free(removed);
        return item;
    }
}

void print_list(LinkedQueueType *q) {                               // ����Ʈ ��� �Լ�
    QueueNode *node = q->front;

    if(q->size == 1){
        printf("%d -> NULL\n", node->data);
        return;
    }

    while (node != NULL) {
        printf("%d-> ", node->data);
        node = node->link;
    }
    printf("NULL\n");
}

int main() {
    LinkedQueueType *progress = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));    // ť ����
    LinkedQueueType *speed = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));
    LinkedQueueType *head = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));
    int n, pro, spe;

    init_queue(&progress);                          // ť �ʱ�ȭ
    init_queue(&speed);
    init_queue(&head);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {                   // ��� �Է�
        scanf("%d", &pro);
        enqueue(&progress, pro);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &spe);
        enqueue(&speed, spe);
    }

    while (progress->size > 0) {
        QueueNode *p = progress->front;
        QueueNode *s = speed->front;
        int cnt = 0;
        n = progress->size;
        for (int i = 0; i < n; i++) {           // ��ɿ� ���ǵ带 ���ϴ� �ݺ���
            if (p == NULL)
                break;
            p->data += s->data;
            p = p->link;
            s = s->link;
        }
        QueueNode *node = progress->front;
        for (int i = 0; i < n; i++) {           // ����� ũ�⸦ Ȯ��
            if (node->data >= 100) {            // 100���� Ŭ�ÿ� ť���� ����
                node = node->link;
                dequeue(&progress);
                dequeue(&speed);
                cnt++;
            }
            else
                break;
        }
        if (cnt > 0) {
            enqueue(&head, cnt);                // �Ϸ翡 �������� ����� head ť�� ����
        }
    }
    print_list(head);
}