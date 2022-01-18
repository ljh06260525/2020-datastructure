#include <stdio.h>
#include <math.h>
int count = 0;
int x=0, y=0;

void Z_func(int n, int r, int c) {
    if (n == 2) {
        if (r == x && c == y) {
            printf("%d", count);
            return;
        }
        count++;

        if (r == x && c + 1 == y) {
            printf("%d", count);
            return;
        }
        count++;

        if (r + 1 == x && c == y) {
            printf("%d", count);
            return;
        }
        count++;

        if (r + 1 == x && c + 1 == y) {
            printf("%d", count);
            return;
        }
        count++;
        return;

    }
    Z_func(n/2, r, c);
    Z_func(n/2, r, c+n/2);
    Z_func(n/2, r+n/2, c);
    Z_func(n/2, r+n/2, c+n/2);
}

int main(){
    int N;
    scanf("%d %d %d", &N, &x, &y);
    Z_func(pow(2, N), 0, 0);
}