#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node {
    char ch;
    struct _node *prev, *next;
} node;

node *start = NULL, *end = NULL, *cursor = NULL;
char start_string[100000];

void init() {
    int len = strlen(start_string);
    if(start == NULL) {
        node *newNode = (node*)malloc(sizeof(node)); 
        start = (node*)malloc(sizeof(node));
        end = (node*)malloc(sizeof(node));
        newNode->ch = start_string[0];
        newNode->prev = start;
        newNode->next = end;
        start->next = newNode;
        start->prev = NULL;
        end->prev = newNode;
        end->next = NULL;
        cursor = end;
    }
    for(int i=1; i<len; i++) {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->ch = start_string[i];
        newNode->prev = cursor->prev;
        newNode->next = cursor;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }
}
void InsertChar(char ch) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->ch = ch;
    newNode->next = cursor;
    newNode->prev = cursor->prev;
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;
}
void MoveCursorLeft() {
    if(cursor->prev != start)
        cursor = cursor->prev;
}
void MoveCursorRight() {
    if(cursor != end)
        cursor = cursor->next;
}
void DeleteChar() {
    if(cursor->prev != start) {
        node *tmp = cursor->prev;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        free(tmp);
    }
}
void PrintNode() {
    for(node *tmp = start->next; tmp != end; tmp = tmp->next)
        printf("%c", tmp->ch);
    printf("\n");
}

int main() {
    char command[5];
    int M;
    scanf("%s", start_string);
    init();
    scanf("%d", &M);
    getchar();
    while(M--) {
        fgets(command, 5, stdin);
        if(command[0] == 'L')
            MoveCursorLeft();
        else if(command[0] == 'D')
            MoveCursorRight();
        else if(command[0] == 'B')
            DeleteChar();
        else if(command[0] == 'P')
            InsertChar(command[2]);   
        else
            printf("unknown command. \n");
    }
    PrintNode();
}