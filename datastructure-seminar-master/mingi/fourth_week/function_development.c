#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct _QueueNode {                 // 연결 리스트에서의 노드 선언
    element data;
    struct _QueueNode *link;
} QueueNode;

typedef struct {                            // 큐의 front와 rear를 구조체로 정의
    QueueNode *front, *rear;
    int size;
} LinkedQueueType;

void init_queue(LinkedQueueType **q) {      // 큐의 초기화(이중 포인터 사용)
    (*q)->front = (*q)->rear = NULL;
    (*q)->size = 0;
}

int is_empty(LinkedQueueType *q) {          // 연결 리스트가 비어있는 지 확인
    return q->rear == NULL;
}

void enqueue(LinkedQueueType **q, element item) {                   // 큐 노드 삽입 연산
    QueueNode *newnode = (QueueNode *) malloc(sizeof(QueueNode));
    if (newnode == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
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

element dequeue(LinkedQueueType **q) {                              // 큐 노드 삭제 연산
    QueueNode *removed = (*q)->front;
    element item = removed->data;
    if (is_empty(*q)) {
        fprintf(stderr, "큐 공백 에러\n");
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

void print_list(LinkedQueueType *q) {                               // 리스트 출력 함수
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
    LinkedQueueType *progress = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));    // 큐 선언
    LinkedQueueType *speed = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));
    LinkedQueueType *head = (LinkedQueueType *) malloc(sizeof(LinkedQueueType));
    int n, pro, spe;

    init_queue(&progress);                          // 큐 초기화
    init_queue(&speed);
    init_queue(&head);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {                   // 요소 입력
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
        for (int i = 0; i < n; i++) {           // 기능에 스피드를 더하는 반복문
            if (p == NULL)
                break;
            p->data += s->data;
            p = p->link;
            s = s->link;
        }
        QueueNode *node = progress->front;
        for (int i = 0; i < n; i++) {           // 요소의 크기를 확인
            if (node->data >= 100) {            // 100보다 클시에 큐에서 삭제
                node = node->link;
                dequeue(&progress);
                dequeue(&speed);
                cnt++;
            }
            else
                break;
        }
        if (cnt > 0) {
            enqueue(&head, cnt);                // 하루에 마무리한 기능을 head 큐에 삽입
        }
    }
    print_list(head);
}