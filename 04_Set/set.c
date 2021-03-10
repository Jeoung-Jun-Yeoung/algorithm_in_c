#include <stdio.h>
#include <stdlib.h>

char parent_array[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'}; // 배열의 초기화를 담당.
int rank_array[9] = { 0 };

void make_set(char data) {

	parent_array[data - 97] = data; //아스키 변환을 통해 출력결과를 char으로 보이게 하기 위한 장치.
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
	
	if (rank_array[index_x] > rank_array[index_y]) { // x의 랭크가 y보다 클때

		parent_array[index_y] = x;

	}
	
	else if (rank_array[index_x] < rank_array[index_y]) { // y의 랭크가 x보다 클때

		parent_array[index_x] = y;

	}

	else { // 랭크가 같을때는 하나의 랭크를 올려주고 붙인다.

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
	
	printf("초기상태입니다.\n");
	
	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");

	Union('a', 'c');
	
	printf("(a)결과물입니다.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");
	
	Union('d', 'f');
	printf("(b)결과물입니다.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	printf("\n");

	Union('a', 'd');

	printf("최종답입니다.\n");

	for (int i = 0; i < 9; i++) {
		printf("%c ", parent_array[i]);
	}
	
	printf("\n");

}