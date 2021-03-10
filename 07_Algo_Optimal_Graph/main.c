#include <stdio.h>

int P[5][1 << 5] = { 0 }; // ���İ��� ���� ������ �迭 P
int D[5][1 << 5] = { 0 }; // �ִ� �Ÿ� ���� �迭 D

int W[5][5] = { 
	{ 0,8,13,18,20 },
	{ 3,0,7,8,10 },
	{ 4,11,0,10,7 }, 
	{ 6,6,7,0,11 }, 
	{ 10,6,2,1,0 } 
}; // w �迭 ����ġ

int traveling_Salesperson() {
	int i;
	int j;
	int k;

	for (i = 1; i < 5; i++) {

		D[i][0] = W[i][0];	//�迭 D�� �ʱ�ȭ. 
	
	}

	for (k = 1; k <= 5 - 2; k++) {
		
		for (int p = 0; p < (1 << (5 - 1)); p++) {	//��� ���� Ž��
			
			int B[5] = { 0 }; //��Ʈ����ŷ���� �湮���θ� ����

			int ck = 0; //�κ� �湮�ѰͿ� ���Խ�Ų ����
			
			int p2 = p; //�κй湮�Ѱ��� ��Ʈ����ŷ���� p2�� �ӽ÷� ������
			
			for (int q = 1; q < 5; q++) {

				if (p2 % 2 == 1) { 
					
					B[q] = 1; // 1�� ǥ��.
					
					ck++; 
				
				}
				
				p2 /= 2;	//��Ʈ����Ű�� ��ȯ
			}

			if (ck == k) {	//Ž���� subset�� ���Ұ����� k�� �� ��

				for (i = 1; i < 5; i++) {
					
					if (B[i] == 0) { //subset�� ���Ե��� ���� �ּ� ��θ� Ž����
						
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

	return real_min; // �ִ� �Ÿ��� ����.
}


int main() {
	int i, j, k, l;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < (1 << 5); j++) {
			P[i][j] = -1;
		}
	}

	int min = traveling_Salesperson(); //�ּ� ��θ� �Լ��� ���ϱ�.

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
	printf("�ּ� ��δ� v1 -> v2 -> v3 -> v5 -> v4 -> v1 �̰�");
	printf("\n�ִ� �Ÿ��� : %d\n", min);
	
}

