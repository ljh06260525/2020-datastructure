//경우의 수 구하기
#include <stdio.h>

long eat_pill(int W, int H);

int pill[30][30] = {0}; //[W][H], W=쪼개지 않은 알약 한개, H = 알약 반개

int main(){
    int N = 0;
    int W, H;
    /*while(scanf("%d", &N) && N != 0){
        printf("%d\n", eat_pill(N, 0));
    }
*/

    for(int i = 0; scanf("%d", &N) && N != 0; i ++){
        eat_pill(N, 0);
    }

    printf("%l\n", pill[W][H]);

    return 0;
}

long eat_pill(int W, int H){
    if(W > 0){ //쪼개지않은 한개의 알약을 먹을 때
        //한개의 알약의 갯수는 하나 줄어들고, 반개 쪼개서 먹었으므로 반개의 갯수가 늘어남
        pill[W][H] += eat_pill(W-1, H + 1);
    }

    if(H > 0){ //반쪼갠 알약을 먹었을 때
        pill[W][H] += eat_pill(W, H -1); // 반개의 알약을 하나 뺀다
    }

    if(W == 0){ //쪼개지 않은 모든 알약을 먹게 되었을 때
        return 1; //남은 알약은 모두 반조각이므로 1을 return (H 문자만 보내게 됨)
        //리턴 1해주지 말고 아예 값을 집어넣어 줄 것
    }

    if(W > 0 && H > 0){//같은 경우의 수가 나오면 그대로 return
        return pill[W][H];
    }

    return pill[W][H]; //최종 경우의 수 return

}
