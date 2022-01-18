#include <stdio.h>

#define SIZE 10

//서로다른 숫자의 수를 출력

int main(void)
{
    int a[SIZE] = { 0 };
    int b = 42;
    int rest[SIZE] = { 0 };
    int i, j, count = 0, tmp[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        tmp[i] = -1; //tmp배열 -1으로 초기화
    }

    int arr_size = sizeof(rest) / sizeof(int);

    for(i = 0; i < SIZE; i++){
        scanf("%d", &a[i]);
        rest[i] = a[i] % b;
        tmp[i] = rest[i];

        for(j = 0; j < SIZE; j++) {
                if(rest[i] == tmp[j] && i != j) { //rest의 원소와 tmp의 원소 모두 한번씩 비교! 단, i ==j와 같을 때는 제외
                    count --;
                    break;
                }
            }
        count ++;
        }

    printf("%d\n", count);
}
