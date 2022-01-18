#include <stdio.h>

typedef struct {
    int ParNod; // parent node
    int flag; // remoflag/exception flag
} Node;

int main()
{
    int treeN, rmv, cnt = 0;
    int i = -1;
    int chk[50] = { 0 }; // visited nodes check
    Node nod[50] = { 0 };
    scanf("%d", &treeN);
    for (int i = 0; i < treeN; i++) {
        scanf("%d", &nod[i].ParNod);
    }
    scanf("%d", &rmv);
    nod[rmv].flag = 1;
    while (i < treeN) { // remove nodes
        i++;
        if ((chk[i] == 0) && (nod[i].flag == 1)) {
            rmv = i;
            chk[i] = 1;
        }
        else continue;
        for (int j = 0; j < treeN; j++) {
            if (nod[j].ParNod == rmv) {
                nod[j].flag = 1;
            }
        }
        i = -1;
    }
    for (int k = 0; k < treeN; k++) { // except parentnodes to count leaf nodes
        if (nod[k].ParNod >= 0 && chk[k] != 1) nod[nod[k].ParNod].flag = 1;
    }
    for (int k = 0; k < treeN; k++) { // count leaf nodes
        if (nod[k].flag == 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}