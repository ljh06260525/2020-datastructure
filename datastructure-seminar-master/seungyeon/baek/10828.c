// 백준 10828 스택

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) //스택 초기화 함수
{
    s->top = -1;
}

int empty(StackType *s) //공백상태 확인 함수
{
    return (s->top == -1);
}

int full(StackType *s) // 포화상태 확인 함수
{
    return ( s->top == (MAX_STACK_SIZE -1));
}

void push(StackType *s, element item) // 삽입함수
{
    if (full(s)){
        fprintf(stderr,"스택 포화 에러 \n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) // 삭제함수
{
    if (empty(s)){
        return -1;
    }
    else return s->data[(s->top)--];
}

element top(StackType *s) // 피크함수
{
    if(empty(s)){
        return -1;
    }
    else return s->data[s->top];
}

element size(StackType *s) // 크기확인 함수
{
    return s->top+1;
}

int main(void)
{
    int i,N;
    int item;
    char str[10];
    StackType stack;
    init_stack(& stack);

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%s", str);
        
        if(!strcmp(str, "push")){
            scanf("%d", &item);
            push(&stack, item);
        }
        else if(!strcmp(str, "pop"))
        {
            printf("%d\n", pop(&stack));
        }
        else if(!strcmp(str, "empty"))
        {
            printf("%d\n", empty(&stack));
        }
        else if(!strcmp(str, "size"))
        {
            printf("%d\n", size(&stack));
        }
        else if(!strcmp(str, "top"))
        {
            printf("%d\n", top(&stack));
        }
    }

return 0;
}