// 백준 2961 도영이가 만든 맛있는 음식

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int MIN = 100000;
int *S, *B;

void Cook(int dep, int a, int Ss, int Bb)
{
    if(dep == a)
    {
        int temp = abs(Ss-Bb);

        if(temp < MIN)
            MIN = temp;
        return;
    }
    for(int i=dep+1; i< N; i++)
    {
        Cook(i, a, Ss*(*(S+i)), Bb+(*(B+i)));
    }
    return;
}

int main(){

    S = (int*)malloc(sizeof(int) * N);
    B = (int*)malloc(sizeof(int) * N);

    scanf("%d",&N);
    if (N >= 1 && N <=10)
        {
            for(int i=0; i<N; i++)
              scanf("%d %d", S+i, B+i);   
            for(int i =0; i<N; i++) // 기준점
                for(int j = 0; j <N; j++) // 비교대상
                {
                    Cook(j,i,*(S+j),*(B+j));
                }
        }
    printf("%d\n",MIN);
    return 0;
}
