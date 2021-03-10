#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct linkedlist { // 링크드리스트 자료형

	int data;
	struct linkedlist* next;

}linkedlist;

int hash_function(int key) { // 해쉬함수

	int hash_value = key % 13;

	return hash_value;

}


int main() {

	linkedlist* array[13] = { NULL };

	// 10 20 30 40 33 46 50 60 intput 갯수.

	int array_count = 8;

	int key = 0;

	while (array_count != 0) { // 반복문횟수

		scanf("%d", &key);

		int after_key = hash_function(key); // 해쉬함수 이후 키값

		if (array[after_key] == NULL) {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist)); // 테이블이 비어있으면 node를 만들어 넣어준다.

			node->data = key;
			node->next = NULL;
			array[after_key] = node;

		}

		else {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist)); // 충돌이 발생하면 노드를 만들어 체이닝한다.
			node->data = key;
			node->next = array[after_key];
			array[after_key] = node;

		}

		printf("출력결과입니다.\n");

		for (int i = 0; i < 13; i++) {

			linkedlist* node = (linkedlist*)malloc(sizeof(linkedlist));
			node->next = array[i];


			if (node->next == NULL) {
				printf("%d index: No Entry\n", i);
			}


			else {

				printf("%d index: ", i);

				while (node->next != NULL) { // 노드를 탐색해가면서 출력한다.

					node = node->next;

					printf("%d ", node->data);

				}

				printf("\n");

			}

		}

		array_count--;

	}



}