#include<stdio.h>
#define N 42

void _remainder(int arr[])
{
    int n = 0;

    for (int i = 0; i < 10; i++) { // 나머지 구해서 저장
        arr[i] = arr[i] % N;
    }

    for (int i = 0; i < 10; i++) { // 하나씩 골라서 비교
        for (int j = i+1; j < 10; j++) { // 자신과 비교 할 필요없음 / 앞은 이미 비교함
            if ( arr[i] == arr[j] ) { // 중복되면 중복되는 자리에 N넣기
                arr[j] = N;
            }
        }
        if (arr[i] != N) {
            n++;
        }
    }
    printf("%d\n", n);
}

int main()
{
    int arr[10] = {0,};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    _remainder(arr);
    return 0;
}