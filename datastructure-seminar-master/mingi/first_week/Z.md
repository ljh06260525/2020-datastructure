# 백준 - 재귀 호출

## Z

- 한수는 2차원 배열(항상 2^N * 2^N 크기이다)을 Z모양으로 탐색한다.

![image-20200109102412845](C:\Users\mgsty\AppData\Roaming\Typora\typora-user-images\image-20200109102412845.png)

- 2차원 배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 4등분 한 후에(크기가 같은 2^(N-1)로) 재귀적으로 순서대로 방문한다.

![image-20200109102705333](C:\Users\mgsty\AppData\Roaming\Typora\typora-user-images\image-20200109102705333.png)

다음 그림은 N=3일 때의 예이다.

![image-20200109102752580](C:\Users\mgsty\AppData\Roaming\Typora\typora-user-images\image-20200109102752580.png)

**문제 설명**

첫째 줄에 입력  N, r, c를 한다. N은 행렬의 크기를 정해주는 변수이고, r과 c는 0보다 크거나 같고 2^N-1보다 작거나 같은 정수이다. r과 c는 2차원 행렬에서의 인덱스를 나타내는 변수들이다.

2차원 행렬 a가 있다고 할때 **a[r] [c]**에 있는 정수를 구하는 문제이다. 

따라서 둘째 줄에 출력으로는 a[r] [c]에 있는 정수가 출력이 된다.