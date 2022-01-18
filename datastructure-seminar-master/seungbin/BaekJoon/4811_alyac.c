#include <stdio.h>

long long aly[31][31] = { 0 };

// aly[w][h] = 알약이 w,h개 남았을 때, 만들 수 있는 글자의 수
long long yac(int w, int h)
{
    if (w == 0) return 1; // 큰 알약이 0개라면 무조건 경우의 수는 1
    if (aly[w][h] > 0) return aly[w][h]; // 이미 경우의 수가 들어 있다면 그 값을 반환
    if (w > 0) aly[w][h] += yac(w - 1, h + 1); // 한개를 빼고 반개를 더할 때
    if (h > 0) aly[w][h] += yac(w, h - 1); // 반개를 뺄 때
    return aly[w][h]; // 경우의 수 반환
}

int main()
{
    int n = 0;
    while(scanf("%d", &n) && n != 0)
    {
        printf("%lld\n",yac(n, 0));
    }
    return 0;
}