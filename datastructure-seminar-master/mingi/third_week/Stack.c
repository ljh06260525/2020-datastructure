#include <stdio.h>
#include <string.h>

int stack[10000];
int top = -1;
int pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}

void push(int element){
    stack[++top] = element;
}

int empty(){
    return top == -1;
}

int return_top(){
    if(top == -1)
        return -1;
    return stack[top];
}
int main(){
    int cnt, num;
    char command[6];
    scanf("%d", &cnt);
    for(int  i = 0; i < cnt; i++){
        scanf("%s", command);
        if(!strcmp(command, "push")){
            scanf("%d", &num);
            push(num);
        }
        else if(!strcmp(command, "pop"))
            printf("%d\n", pop());
        else if (!strcmp(command, "empty"))
            printf("%d\n", empty());
        else if(!strcmp(command, "top"))
            printf("%d\n", return_top());
        else
            printf("%d\n", top+1);
    }
}