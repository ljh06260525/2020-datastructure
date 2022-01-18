#include <stdio.h>
#include <math.h>

int visit = 0;

void Z(int area, int x, int y, int r, int c){
    int add = (int)sqrt(area) / 2 ;

    if(area == 4){
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                if(i == r && j == c){
                    printf("%d\n", visit);
                    return;
                }
                visit += 1;
            }
        }
        return;
    }

    else{
        Z(area/4, x, y, r, c);
        Z(area/4, x, y+(add), r, c);
        Z(area/4, x+(add), y, r, c);
        Z(area/4, x+(add), y+(add), r, c);
    }
}

int main(void)
{
    int N, r, c;
    int size, area;
    int x = 0, y = 0;

    scanf("%d %d %d", &N, &r, &c);
    size = (int)pow(2, N);
    area = size * size;
    
    Z(area, x, y, r, c);
}