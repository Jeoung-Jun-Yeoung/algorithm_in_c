#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct linkedlist { // ��ũ�帮��Ʈ �ڷ���

	int data;
	struct linkedlist* next;

}linkedlist;

int hash_function(int key) { // �ؽ��Լ�

	int hash_value = key % 13;

	return hash_value;

}


int main() {

	linkedlist* array[13] = { NULL };

	// 10 20 30 40 33 46 50 60 intput ����.

	int array_count = 8;

	int key = 0;

	while (array_count != 0) { // �ݺ���Ƚ��

		scanf("%d", &key);

		int after_key = hash_function(key); // �ؽ��Լ� ���� Ű��

		if (array[after_key] == NULL) {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist)); // ���̺��� ��������� node�� ����� �־��ش�.

			node->data = key;
			node->next = NULL;
			array[after_key] = node;

		}

		else {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist)); // �浹�� �߻��ϸ� ��带 ����� ü�̴��Ѵ�.
			node->data = key;
			node->next = array[after_key];
			array[after_key] = node;

		}

		printf("��°���Դϴ�.\n");

		for (int i = 0; i < 13; i++) {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist));
			node->next = array[i];


			if (node->next == NULL) {
				printf("%d index: No Entry\n", i);
			}


			else {

				printf("%d index: ", i);

				while (node->next != NULL) { // ��带 Ž���ذ��鼭 ����Ѵ�.

					node = node->next;

					printf("%d ", node->data);

				}

				printf("\n");

			}

		}

		array_count--;

	}



}