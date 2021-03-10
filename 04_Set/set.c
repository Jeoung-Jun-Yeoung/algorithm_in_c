#include <stdio.h>
#include <stdlib.h>

char parent_array[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'}; // �迭�� �ʱ�ȭ�� ���.
int rank_array[9] = { 0 };

void make_set(char data) {

	parent_array[data - 97] = data; //�ƽ�Ű ��ȯ�� ���� ��°���� char���� ���̰� �ϱ� ���� ��ġ.
	rank_array[data - 97] = 0;

}

char Find_Set(char x) {

	if (x == parent_array[x - 97]) {

		return x;

	}

	else {

		return Find_Set(parent_array[x - 97]);

	}

}


void Union(char x, char y) {
	
	x = Find_Set(x);
	y = Find_Set(y);

	int index_x = x - 97;
	int index_y = y - 97;
	
	if (rank_array[index_x] > rank_array[index_y]) { // x�� ��ũ�� y���� Ŭ��

		parent_array[index_y] = x;

	}
	
	else if (rank_array[index_x] < rank_array[index_y]) { // y�� ��ũ�� x���� Ŭ��

		parent_array[index_x] = y;

	}

	else { // ��ũ�� �������� �ϳ��� ��ũ�� �÷��ְ� ���δ�.

		rank_array[index_x]++;
		parent_array[index_y] = x;

	}
	
}


int main() {
	
	Union('a', 'b');
	Union('d', 'e');
	Union('f', 'g');
	Union('f', 'h');
	Union('f', 'i');
	
	printf("�ʱ�����Դϴ�.\n");
	
	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");

	Union('a', 'c');
	
	printf("(a)������Դϴ�.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");
	
	Union('d', 'f');
	printf("(b)������Դϴ�.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");

	Union('a', 'd');

	printf("�������Դϴ�.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	
	printf("\n");

}