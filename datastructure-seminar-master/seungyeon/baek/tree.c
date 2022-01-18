#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int root;
    int child[51];
    int idx;
} Node;

Node treeList[51] = {0};

int removeNode(int node)
{
    for(int i = 0; i<51; i++)
    {
        if(treeList[node].child[i] == 1)
        {
            removeNode(i);
            treeList[node].child[i] = -1;
        }
    }
    treeList[node].idx = 0;
    treeList[node].root = -2;
    return 0;
}

int main (void)
{
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d",&a);
        treeList[i].root = a ;
        if(a != -1){
            treeList[a].child[i] = 1;
            treeList[a].idx++;
        }
    }
    int node;
    scanf("%d", &node);
    if(treeList[node].root == -1){
        printf("%d", 0);
        return 0;
    }
    
    int root = treeList[node].root;
    treeList[root].idx--;
    treeList[root].child[node]=-1;

    removeNode(node);
    int count = 0;
    for(int i = 0; i <N; i++)
    {
        if(treeList[i].root != -2 && treeList[i].idx == 0)
        {
            count++;
        }
    }

printf("%d\n",count);
}