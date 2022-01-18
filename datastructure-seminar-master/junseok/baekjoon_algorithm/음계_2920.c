#include <stdio.h>

int main(){
    int scale[8], n, cnt = 0;
    for(int i=0; i<8; i++){
        scanf("%d", &n);
        scale[i] = n;
    }

    if(scale[0] == 1){
        for(int i=0; i<8; i++){
            if(scale[i] == i+1)
                cnt++;
        }
        if(cnt == 8)
            printf("ascending\n");
        else
            printf("mixed");
    }

    else if(scale[0] == 8){
        for(int i=7; i>=0; i--){
            if(scale[7 - i] == i+1)
                cnt++;
        }
        if(cnt == 8)
            printf("descending\n");
        else
            printf("mixed\n");
    }

    else
        printf("mixed\n");
}