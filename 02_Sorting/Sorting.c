#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int print_count; // merge, quick, heap함수들의 출력횟수 변수.



void Selection_Sort(float array[], int  n) {

	float max = -10.0;
	int max_index = 0;

	for (int i = n - 1; i >= 1; i--) { // 반복문이 도는 범위를 정해준다.

		for (int j = 0; j <= i; j++) { // 첫번째 반복문에서 정한 범위를 돌면서 최대값을 찾아준다.

			if (max < array[j]) {
				max = array[j];
				max_index = j;
			}
		}

		array[max_index] = array[i]; // 선택한 최댓값을 last_index값과 swap한다.
		array[i] = max;
		max = -10.0;
		max_index = 0;

	}
}


void Bubble_Sort(float array[], int n) {

	for (int i = n - 1; i >= 1; i--) { // 첫번째 for문으로 보는 범위를 정해준다. 

		for (int j = 0; j < i; j++) { // 두번째 for문은 앞에 for문으로 정한 범위를 보면서 실제로 정렬을 한다.

			if (array[j] > array[j + 1]) {	// swap하는 코드.
				float temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

		}
	}
}


void Insertion_Sort(float array[], int n) {

	float standard = -10.0;

	for (int i = 0; i < n; i++) {

		standard = array[i];

		for (int j = i - 1; j >= 0; j--) { // 삽입할 범위를 탐색한다.
											//아래 코드를 통해 적당한 자리를 찾아 삽입을 해준다.
			if (array[j] > standard) {

				array[j + 1] = array[j];

				if (j == 0) {
					array[j] = standard;
				}
			}
			else {

				array[j + 1] = standard;
				break;

			}

		}


	}

}

void merge(float array[], int p, int r, int mid) {

	int k = mid + 1; // 

	float temp_array[20000] = { 0.0 }; // 배열사이즈를 넉넉히 잡음. over_flow방지

	int temp_index = p; //temp_array에 값을 담으면서 하나씩 증가.

	int before_p = p; // temp_array의 값을 기존 array에 담을때 p값을 증가시키면서, 기존의 p값을 잃었기 때문에 미리 저장함.

	while (p <= mid && k <= r) { // 대소관계를 비교후 정렬. 왼쪽이 mid에 접근하거나, k가 r에 접근하면 종료.

		if (array[p] <= array[k]) {
			temp_array[temp_index] = array[p];
			temp_index++;
			p++;
		}

		else {
			temp_array[temp_index] = array[k];
			k++;
			temp_index++;
		}
	}

	while (p <= mid) { // 왼쪽이 남아있으면 나머지 값들을 넣어줌.

		temp_array[temp_index] = array[p];
		temp_index++;
		p++;

	}

	while (k <= r) { // 오른쪽이 남아있으면 나머지 값들을 넣어줌.

		temp_array[temp_index] = array[k];
		temp_index++;
		k++;

	}

	for (int i = before_p; i <= r; i++) { // temp_array에 담긴 정렬된 값들을 기존 array에 담아줌.

		array[i] = temp_array[i]; // [befor_p]를 담아서 오류가 났었음.

	}

}



void Merge_Sort(float array[], int p, int r) {

	if (p < r) { //정렬할 array가 1개일때 까지 나눈다.

		int mid = (p + r) / 2; //중간값설정.

		Merge_Sort(array, p, mid); // recursive for left sorting 
		Merge_Sort(array, mid + 1, r); //recursive for right sorting 
		merge(array, p, r, mid);


	}
}




void swap(float array[], int left, int right) { //swap하는 함수로서 코드에서 반복되어서 따로 함수를 만들었다.

	float temp = array[left];

	array[left] = array[right];
	array[right] = temp;

}



int Partition(float array[], int left, int right) { // pivot을 중심으로 파트를 나누는 함수이다.

	int pivot = right;

	int start_left = left;
	int start_right = right - 1;

	while (start_left <= start_right) { // left와 right가 교차전까지 반복.

		while (start_left <= right - 1) { // left에서 출발하면서 pivot보다 큰값을 탐색.

			if (array[start_left] > array[pivot]) { // 찾으면 break.
				break;
			}

			start_left++;

		}

		while (start_right >= left) { //right에서 출발해서 pivot보다 작은값을 탐색.

			if (array[start_right] < array[pivot]) { // 찾으면 break
				break;
			}

			start_right--;

		}

		if (start_left <= start_right) { // 바꿀수있으면, swap함수를 통해 바꾼다.

			swap(array, start_left, start_right); // 

		}

	}

	swap(array, start_left, pivot); // 최종적으로 loop가 한번 돌면 pivot자리를 맞는 위치에 고정해준다.

	return start_left;

}

void Quick_Sort(float array[], int p, int r) { // quick sort함수이다. 

	if (p < r) { // 기저조건

		int q = Partition(array, p, r);

		Quick_Sort(array, p, q - 1); // pivot을 중심으로 왼쪽 part를 quick_sort한다. 
		Quick_Sort(array, q + 1, r); // pivot을 중심으로 오른쪽 part를 quick_sort한다.

	}

}

void heapify(float array[], int layer, int n) {


	int left_child = (layer * 2) + 1; // 왼쪽자식 

	int right_child = (layer * 2) + 2; // 오른쪽자식

	int min = layer;

	if (left_child < n && array[layer] > array[left_child]) {

		min = left_child;

	}

	if (right_child < n && array[min] > array[right_child]) {

		min = right_child;

	}

	if (min != layer) {
		swap(array, min, layer); //heap을 유지하기위해 swap한다.
		heapify(array, min, n);
	}

}

void build_heap(float array[], int n) { // 최초의 배열을 heap으로 만들어 준다.

	for (int i = n - 1; i >= 0; i--) {
		heapify(array, i, n);
	}

}

void Heap_sort(float array[], int n) { // heap_sort를 실행한다.

	build_heap(array, n); // 최초의 배열을 heap으로 만든다.

	for (int i = n - 1; i > 1; i--) { // root값과 last_index의 값을 바꿔준다.

		float temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		heapify(array, 0, i - 1); // re_heap을 통해 다시 최솟값을 찾는것을 반복한다.

	}


}


int main() {
	clock_t start, end;
	//int array[] = { 12, 70, 30, 20, 55, 25, 40, 50 };

	int n = 8; // index갯수

	int p = 0; //0번째 index

	int r = 7; // last index



	printf("Selection_Sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}



		start = clock();
		Selection_Sort(array, k);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}

	printf("Bubble_sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}



		start = clock();
		Bubble_Sort(array, k);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}


	printf("Insertion_Sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}



		start = clock();
		Insertion_Sort(array, k);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}

	printf("Merge_Sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}



		start = clock();
		Merge_Sort(array, 0, k - 1);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}




	printf("Quick_Sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}



		start = clock();
		Quick_Sort(array, 0, k - 1);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}

	printf("Heap_sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed값으로 제출 날짜를 넣어줌.
		for (int i = 0; i < k; i++) {

			float a = (rand() % 2001) / 1000.0 - 1;
			array[i] = a;
		}


		start = clock();
		Heap_sort(array, k);
		end = clock();
		double result = (double)(end - start);
		printf("%0.0lf \n", result);
	}



}



