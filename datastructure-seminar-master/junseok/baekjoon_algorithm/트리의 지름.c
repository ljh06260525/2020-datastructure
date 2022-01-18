#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100001
int visited[MAX_VERTICES];
typedef struct _GraphNode {
    int vertex;
    int edge_length;
    struct _GraphNode *link;
} GraphNode;
typedef struct _GraphType {
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

typedef struct _StackType {
    int stack[MAX_VERTICES];
    int top;    
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

void push(StackType *s, int item) {
    s->stack[++(s->top)] = item;
}

int pop(StackType *s) {
    if(is_empty(s)) fprintf(stderr, "error\n");
    return s->stack[(s->top)--];
}

// 그래프 초기화
void init(GraphType *g) {
    for(int v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// 간선 삽입, v를 u의 인접 리스트로 삽입
void insert_edge(GraphType *g, int u, int v, int edge_length) {
    GraphNode *node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
    g->adj_list[u]->edge_length = edge_length;
}
int res, idx;
// dfs
void dfs_list(GraphType *g, int v, int max) {
    GraphNode *w;
    // StackType s;
    // push(&s, v);
    // while(!is_empty(&s)) {
    //     v = pop(&s);
    //     if(max > res) {
    //         res = max;
    //         idx = v;
    //         printf("res : [%d], v : [%d]\n", res, v);
    //     }
    //     if(visited[v] != TRUE) {
    //         visited[v] = TRUE;
    //         for(w=g->adj_list[v]; w; w=w->link) {
    //             if(visited[w->vertex] != TRUE) {
    //                 max += w->edge_length;
    //                 push(&s, w->vertex);
    //             }
    //         }
    //     }
    // }
    if(max > res) {
        res = max;
        idx = v;
    }
    visited[v] = TRUE;
    for(w=g->adj_list[v]; w; w=w->link) {
        if(visited[w->vertex] != TRUE)
            dfs_list(g, w->vertex, max + w->edge_length);
    }
}

// void print(GraphType *g) {
//     for (int i=1; i<=9; i++) {
//         GraphNode *p = g->adj_list[i];
//         printf("정점 %d의 인접리스트 ", i);
//         while(p != NULL) {
//             printf("-> %d ", p->vertex);
//             p = p->link;
//         }
//         printf("\n");
//     }
// }

int main() { 
    int V, vertex, adj_node, edge_length;
    GraphType g;
    init(&g);
    scanf("%d", &V);
    while(V--) {
        scanf("%d", &vertex);
        while(1) {
            scanf("%d", &adj_node);
            if(adj_node == -1)
                break;
            scanf("%d", &edge_length);
            insert_edge(&g, vertex, adj_node, edge_length);
        }
    }
    // print(&g);
    res = 0;
    dfs_list(&g, 1, 0);
    // 방문 초기화
    for(int i=0; i<MAX_VERTICES; i++)
        visited[i] = FALSE;

    res = 0;
    dfs_list(&g, idx, 0);
    printf("%d\n", res);
}