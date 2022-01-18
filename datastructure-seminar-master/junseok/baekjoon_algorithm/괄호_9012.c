#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 51

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

int is_empty(StackType *s){
    return (s->top == -1);
}

void init_stack(StackType *s){
    for(int i=0; i<MAX_STACK_SIZE; i++)
        s->data[i] = 0;
    s->top = -1;
}

void push(StackType *s, element item){
    s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        return 0;
    }
    return s->data[(s->top)--];
}

void bracket(StackType *s, char *str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == '(')
            push(s, str[i]);
        else{
            if(!pop(s)){
                printf("NO\n");
                return;
            }
        }
    }
    if(is_empty(s))
        printf("YES\n");
    else
        printf("NO\n");
}

int main(){
    StackType s;
    int N;
    char str[51];

    scanf("%d", &N);
    getchar();
    while(N--){
        init_stack(&s);
        scanf("%s", str);
        bracket(&s, str);
    }    
}