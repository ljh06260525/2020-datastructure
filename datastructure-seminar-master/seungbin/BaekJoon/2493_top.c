#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct _StackNode {
    element val;
    int index;
    struct _StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

void push(LinkedStackType *s, element data, int id)
{
    StackNode *new = (StackNode *)malloc(sizeof(element));
    new->val = data;
    new->index = id;
    new->link = s->top;
    s->top = new;
}

StackNode pop(LinkedStackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백에러");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        StackNode popnode;
        popnode.val = temp->val;
        popnode.index = temp->index;
        s->top = s->top->link;
        free(temp);
        return popnode;
    }
}

StackNode peek(LinkedStackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음");
        exit(1);
    }
    StackNode peeknode;
    peeknode.val = s->top->val;
    peeknode.index = s->top->index;
    return peeknode;
}

int* top_sol(int *H, int N, int *res)
{
    LinkedStackType s;
    init(&s);
    push(&s, H[0], 1);
    for (int i = 1; i < N; i++) {
        while (H[i] > peek(&s).val) {
            pop(&s);
            if (is_empty(&s)) {
                push(&s, H[i], i+1);
                break;
            }
            else if (H[i] < peek(&s).val) {
                res[i] = peek(&s).index;
                push(&s, H[i], i+1);
            }
        }
        if (H[i] < peek(&s).val) {
            res[i] = peek(&s).index;
            push(&s, H[i], i+1);
        }
    }
    return res;
}

int main()
{
    int N;
    int *H = NULL;
    int *res = NULL;

    scanf("%d", &N);

    H = (int *)malloc(sizeof(int)*N);
    res = (int *)malloc(sizeof(int)*N);
    memset(res, 0, sizeof(int)*N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    res = top_sol(H, N, res);
    for(int i = 0; i < N; i++) {
        printf("%d ", res[i]);
    }
    
    free(H);
    free(res);
    return 0;
}