#include <stdio.h>;

int hash_function(int key) {

	int hash_value = key % 13;

	return hash_value;


}

// 10 20 30 40 33 46 50 60 intput ����.

int main() {

	int array[13] = { 0 };

	int key = 0;

	int array_count = 8; // input ������ �ݺ��� ����.

	while (array_count != 0) {

		scanf("%d", &key);

		for (int i = 0; i < 13; i++) {

			int after_key = hash_function(key + i); // ����������.

			if (array[after_key] == 0) {

				array[after_key] = key;

				break;

			}

		}

		printf("����Դϴ�.\n");

		for (int i = 0; i <= 12; i++) {

			printf("Index : %d Value : %d\n", i, array[i]);

		}

		array_count--;

	}

}