#include <stdio.h>

int P[5][1 << 5] = { 0 }; // 거쳐가는 것을 저장할 배열 P
int D[5][1 << 5] = { 0 }; // 최단 거리 저장 배열 D

int W[5][5] = { 
	{ 0,8,13,18,20 },
	{ 3,0,7,8,10 },
	{ 4,11,0,10,7 }, 
	{ 6,6,7,0,11 }, 
	{ 10,6,2,1,0 } 
}; // w 배열 가중치

int traveling_Salesperson() {
	int i;
	int j;
	int k;

	for (i = 1; i < 5; i++) {

		D[i][0] = W[i][0];	//배열 D의 초기화. 
	
	}

	for (k = 1; k <= 5 - 2; k++) {
		
		for (int p = 0; p < (1 << (5 - 1)); p++) {	//모든 지점 탐색
			
			int B[5] = { 0 }; //비트마스킹으로 방문여부를 저장

			int ck = 0; //부분 방문한것에 포함시킨 갯수
			
			int p2 = p; //부분방문한것을 비트마스킹으로 p2에 임시로 저장함
			
			for (int q = 1; q < 5; q++) {

				if (p2 % 2 == 1) { 
					
					B[q] = 1; // 1로 표시.
					
					ck++; 
				
				}
				
				p2 /= 2;	//비트마스키를 전환
			}

			if (ck == k) {	//탐색한 subset의 원소갯수가 k개 일 때

				for (i = 1; i < 5; i++) {
					
					if (B[i] == 0) { //subset에 포함되지 않은 최소 경로를 탐색함
						
						int standard = 10000; 
						int min = 0;
						
						for (j = 1; j < 5; j++) {
						
							if (standard > W[i][j] + D[j][(p << 1) - (1 << j)] && B[j] == 1) { 
								
								min = j;
								
								standard = W[i][j] + D[j][(p << 1) - (1 << j)]; 
								
							}
						
						} 
						
						P[i][p << 1] = min; 
					
						D[i][p << 1] = standard;

					}
				}
			}
		}
	}
	
	int minp = 0;

	int real_min = 10000;

	for (j = 1; j < 5; j++) {
		
		if (real_min > W[0][j] + D[j][((1 << 5) - 1) - 1 - (1 << j)]) {
		
			real_min = W[0][j] + D[j][((1 << 5) - 1) - 1 - (1 << j)];
		
			minp = j;
	
		}
	
	}
	
	P[0][((1 << 5) - 1) - 1] = minp;

	D[0][((1 << 5) - 1) - 1] = real_min;

	return real_min; // 최단 거리를 리턴.
}


int main() {
	int i, j, k, l;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < (1 << 5); j++) {
			P[i][j] = -1;
		}
	}

	int min = traveling_Salesperson(); //최소 경로를 함수로 구하기.

	for (i = 0; i < 5; i++) 
	{
		printf("D[v%d][bitA]", i + 1);
		
		for (j = 0; j < (1 << 5); j++) {
			
			if (j % 2 == 1)

				
				continue;
			
			printf("%5d ", D[i][j]);
		
		}
		
		printf("\n");
	
	}

	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------");
	printf("\n");

	for (i = 0; i < 5; i++) {
		
		printf("P[v%d][bitA]", i + 1);
		
		for (j = 0; j < (1 << 5); j++) {
		
			if (j % 2 == 1)
			
				continue;
			
			printf("%5d ", P[i][j] + 1);
		
		}
		
		printf("\n");
	
	}

	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------");
	printf("\n");
	printf("최소 경로는 v1 -> v2 -> v3 -> v5 -> v4 -> v1 이고");
	printf("\n최단 거리는 : %d\n", min);
	
}

