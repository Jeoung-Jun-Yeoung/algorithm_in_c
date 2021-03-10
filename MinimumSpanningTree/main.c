#include <stdio.h>
#include <stdlib.h>

#define infi 10000

typedef struct krsu {

	int weight;
	int start;
	int end;

}ks;


int parent[9]; // kruscalǮ�̸� ���� ��ǥ

void pirm(int n, int w[9][9]) {

	int vnear = 0; // �� �������� ���� ����� �ε���

	int nearest[9] = { 0 }; // Ȯ�尡�ɼ��� �ִ� ������ �ε���

	int f[9][9] = { {0} };

	int distance[9] = { 0 }; // �װ��� �Ÿ�

	for (int i = 2; i <= n; i++) {
		nearest[i] = 1; // v1�� ��� �������� ���ڴ�.
		distance[i] = w[1][i]; //�� �������� v1������ ����ġ
	}

	int idex = 1;

	
	printf("�����˰��� ����Դϴ�.\n");

	printf("\n");

	while (idex <= n - 1) {

		int min = infi;

		for (int i = 2; i <= n; i++) {

			if (0 <= distance[i] && distance[i] <= min) {
				min = distance[i]; // ������ ���ؼ� ����ġ(distance)�� ������ ���� ����ġ�� ����(vnear)�� ã�Ƴ�
				vnear = i;
			}

		}

		f[nearest[vnear]][vnear] = 1;

		printf("V%d ---- V%d\n", nearest[vnear], vnear);

		distance[vnear] = -1;

		for (int i = 2; i <= n; i++) {

			if (w[i][vnear] < distance[i]) { //a���� ���İ��°� ���� �Ÿ����� ������

				distance[i] = w[i][vnear]; // ���İ��°� �ּ��ΰ����� ����.

				nearest[i] = vnear; // �׷� ����� ������ ��ó�� ���� vnear��. 

			}
		}
		idex++;
	}

}

int find(int x) {

	if (x == parent[x]) {

		return x;

	}

	else {

		int y = find(parent[x]);

		parent[x] = y;

		return y;

	}

}

void union_set(int x, int y) { //ũ�罺Į�˰��򿡼� �ʿ��� ���Ͽ��Լ�

	int x_parent = find(x);
	int y_parent = find(y);

	if (x_parent <= y_parent) {

		parent[y] = x_parent;

	}
	else {
		parent[x] = y_parent;
	}

}


void kruskal(int n, int w[9][9]) {


	for (int i = 0; i <= n; i++) {

		parent[i] = i;

	}

	ks* ks_array[15];
	int ks_index = 1;
	for (int diagonal = 1; diagonal <= n; diagonal++) { // diagonal�� �������� �밢�� ���� �ȴ�.
		for (int j = diagonal; j <= n; j++) {

			ks* object = (ks*)malloc(sizeof(ks));

			if (w[diagonal][j] != 0 && w[diagonal][j] != infi) {
				object->weight = w[diagonal][j];

				object->start = diagonal;

				object->end = j;

				ks_array[ks_index] = object;
				ks_index++;
			}
		}
	}

	int min = infi;
	int start = 0;
	int end = 0;
	int temp = 0;

	for (int i = 1; i <= 14; i++) {
		min = infi;
		for (int j = 1; j <= 14; j++) {
			if (ks_array[j]->weight < min) { // ���� ����ġ�� ã�� ������.

				temp = j;

				min = ks_array[j]->weight;

				start = ks_array[j]->start;

				end = ks_array[j]->end;
				
			}

		}

		ks_array[temp]->weight = infi; // ã���� �ʱ�ȭ
		
	

		if (find(start) != find(end)) {
			printf("V%d --- V%d\n", start, end); //��� �Լ�.
			union_set(start, end);
			
		}

	}



}









int main() {

	int weight[9][9] = {
		{0,0,0,0,0,0,0,0},
		{0,0,11,9,8,infi,infi,infi,infi},
		{0,11,0,3,infi,8,8,infi,infi},
		{0,9,3,0,15,infi,12,1,infi},
		{0,8,infi,15,0,infi,infi,10,infi},
		{0,infi,8,infi,infi,0,7,infi,4},
		{0,infi,8,12,infi,7,0,infi,5},
		{0,infi,infi,1,10,infi,infi,0,2},
		{0,infi,infi,infi,infi,4,5,2,0}
	};

	printf("\n");
	pirm(8, weight);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("kruskal�Լ� ��� �Դϴ�.\n");
	printf("\n");
	kruskal(8, weight);
}
