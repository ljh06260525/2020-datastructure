#include<stdio.h>
#include<stdlib.h>
// 원형 연결리스트
typedef int element;
typedef struct _LinkedList {
    element number;
    struct _LinkedList *link;
} LinkedList;

LinkedList* insert(LinkedList *head, element data)
{
    LinkedList *new = (LinkedList *)malloc(sizeof(LinkedList));
    new->number = data;
    if (head == NULL) {
        head = new;
        new->link = new;
    }
    else {
        new->link = head->link;
        head->link = new;
        head = new;
    }
    return head;
}

LinkedList* delete(LinkedList *pre, int K)
{
    LinkedList *removed;
    for(int i = 1; i < K; i++) {
        pre = pre->link;
    }
    removed = pre->link;
    element data = removed->number;
    pre->link = removed->link;
    if (pre != removed) {
        printf("%d, ", data);
    }
    else {
        printf("%d>\n", data);
    }
    free(removed);
    return pre;
}

void josephus(int N, int K)
{
    LinkedList *head = NULL;
    LinkedList *pre;

    for (int i = 1; i <= N; i++) {
        head = insert(head, i);
    }

    pre = head;
    printf("<");
    
    for (int i = 0; i < N; i++) {
        pre = delete(pre, K);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    josephus(n, k);
    return 0;
}