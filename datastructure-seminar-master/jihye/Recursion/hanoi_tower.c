#include <stdio.h>

void hanoi(int n, char from, char tmp, char to);
int count = 0;

int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, '1', '2', '3');
    printf("%d\n", count);
    return 0;
}

void hanoi(int n, char from, char tmp, char to)
{
    if(n == 1){
        printf("%c %c\n", from, to);
        count ++;
    }
    else if(n > 100){
        printf("가능한 범위를 초과하였습니다.\n");
    }
    else if(n < 20){
        hanoi(n-1, from, to, tmp);
        printf("%c %c\n", from, to);
        hanoi(n-1, tmp, from, to);
        count ++;
    }
}
