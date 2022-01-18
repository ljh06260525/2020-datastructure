#include <stdio.h>

long long aly[31][31] = { 0 };

// aly[w][h] = �˾��� w,h�� ������ ��, ���� �� �ִ� ������ ��
long long yac(int w, int h)
{
    if (w == 0) return 1; // ū �˾��� 0����� ������ ����� ���� 1
    if (aly[w][h] > 0) return aly[w][h]; // �̹� ����� ���� ��� �ִٸ� �� ���� ��ȯ
    if (w > 0) aly[w][h] += yac(w - 1, h + 1); // �Ѱ��� ���� �ݰ��� ���� ��
    if (h > 0) aly[w][h] += yac(w, h - 1); // �ݰ��� �� ��
    return aly[w][h]; // ����� �� ��ȯ
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