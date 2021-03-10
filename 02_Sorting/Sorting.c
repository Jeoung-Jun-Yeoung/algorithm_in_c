#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int print_count; // merge, quick, heap�Լ����� ���Ƚ�� ����.



void Selection_Sort(float array[], int  n) {

	float max = -10.0;
	int max_index = 0;

	for (int i = n - 1; i >= 1; i--) { // �ݺ����� ���� ������ �����ش�.

		for (int j = 0; j <= i; j++) { // ù��° �ݺ������� ���� ������ ���鼭 �ִ밪�� ã���ش�.

			if (max < array[j]) {
				max = array[j];
				max_index = j;
			}
		}

		array[max_index] = array[i]; // ������ �ִ��� last_index���� swap�Ѵ�.
		array[i] = max;
		max = -10.0;
		max_index = 0;

	}
}


void Bubble_Sort(float array[], int n) {

	for (int i = n - 1; i >= 1; i--) { // ù��° for������ ���� ������ �����ش�. 

		for (int j = 0; j < i; j++) { // �ι�° for���� �տ� for������ ���� ������ ���鼭 ������ ������ �Ѵ�.

			if (array[j] > array[j + 1]) {	// swap�ϴ� �ڵ�.
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

		for (int j = i - 1; j >= 0; j--) { // ������ ������ Ž���Ѵ�.
											//�Ʒ� �ڵ带 ���� ������ �ڸ��� ã�� ������ ���ش�.
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

	float temp_array[20000] = { 0.0 }; // �迭����� �˳��� ����. over_flow����

	int temp_index = p; //temp_array�� ���� �����鼭 �ϳ��� ����.

	int before_p = p; // temp_array�� ���� ���� array�� ������ p���� ������Ű�鼭, ������ p���� �Ҿ��� ������ �̸� ������.

	while (p <= mid && k <= r) { // ��Ұ��踦 ���� ����. ������ mid�� �����ϰų�, k�� r�� �����ϸ� ����.

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

	while (p <= mid) { // ������ ���������� ������ ������ �־���.

		temp_array[temp_index] = array[p];
		temp_index++;
		p++;

	}

	while (k <= r) { // �������� ���������� ������ ������ �־���.

		temp_array[temp_index] = array[k];
		temp_index++;
		k++;

	}

	for (int i = before_p; i <= r; i++) { // temp_array�� ��� ���ĵ� ������ ���� array�� �����.

		array[i] = temp_array[i]; // [befor_p]�� ��Ƽ� ������ ������.

	}

}



void Merge_Sort(float array[], int p, int r) {

	if (p < r) { //������ array�� 1���϶� ���� ������.

		int mid = (p + r) / 2; //�߰�������.

		Merge_Sort(array, p, mid); // recursive for left sorting 
		Merge_Sort(array, mid + 1, r); //recursive for right sorting 
		merge(array, p, r, mid);


	}
}




void swap(float array[], int left, int right) { //swap�ϴ� �Լ��μ� �ڵ忡�� �ݺ��Ǿ ���� �Լ��� �������.

	float temp = array[left];

	array[left] = array[right];
	array[right] = temp;

}



int Partition(float array[], int left, int right) { // pivot�� �߽����� ��Ʈ�� ������ �Լ��̴�.

	int pivot = right;

	int start_left = left;
	int start_right = right - 1;

	while (start_left <= start_right) { // left�� right�� ���������� �ݺ�.

		while (start_left <= right - 1) { // left���� ����ϸ鼭 pivot���� ū���� Ž��.

			if (array[start_left] > array[pivot]) { // ã���� break.
				break;
			}

			start_left++;

		}

		while (start_right >= left) { //right���� ����ؼ� pivot���� �������� Ž��.

			if (array[start_right] < array[pivot]) { // ã���� break
				break;
			}

			start_right--;

		}

		if (start_left <= start_right) { // �ٲܼ�������, swap�Լ��� ���� �ٲ۴�.

			swap(array, start_left, start_right); // 

		}

	}

	swap(array, start_left, pivot); // ���������� loop�� �ѹ� ���� pivot�ڸ��� �´� ��ġ�� �������ش�.

	return start_left;

}

void Quick_Sort(float array[], int p, int r) { // quick sort�Լ��̴�. 

	if (p < r) { // ��������

		int q = Partition(array, p, r);

		Quick_Sort(array, p, q - 1); // pivot�� �߽����� ���� part�� quick_sort�Ѵ�. 
		Quick_Sort(array, q + 1, r); // pivot�� �߽����� ������ part�� quick_sort�Ѵ�.

	}

}

void heapify(float array[], int layer, int n) {


	int left_child = (layer * 2) + 1; // �����ڽ� 

	int right_child = (layer * 2) + 2; // �������ڽ�

	int min = layer;

	if (left_child < n && array[layer] > array[left_child]) {

		min = left_child;

	}

	if (right_child < n && array[min] > array[right_child]) {

		min = right_child;

	}

	if (min != layer) {
		swap(array, min, layer); //heap�� �����ϱ����� swap�Ѵ�.
		heapify(array, min, n);
	}

}

void build_heap(float array[], int n) { // ������ �迭�� heap���� ����� �ش�.

	for (int i = n - 1; i >= 0; i--) {
		heapify(array, i, n);
	}

}

void Heap_sort(float array[], int n) { // heap_sort�� �����Ѵ�.

	build_heap(array, n); // ������ �迭�� heap���� �����.

	for (int i = n - 1; i > 1; i--) { // root���� last_index�� ���� �ٲ��ش�.

		float temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		heapify(array, 0, i - 1); // re_heap�� ���� �ٽ� �ּڰ��� ã�°��� �ݺ��Ѵ�.

	}


}


int main() {
	clock_t start, end;
	//int array[] = { 12, 70, 30, 20, 55, 25, 40, 50 };

	int n = 8; // index����

	int p = 0; //0��° index

	int r = 7; // last index



	printf("Selection_Sort\n");

	for (int k = 10000; k <= 100000; k = k + 10000) {

		float* array = (float*)malloc(sizeof(float) * k);
		srand(20200922); // seed������ ���� ��¥�� �־���.
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
		srand(20200922); // seed������ ���� ��¥�� �־���.
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
		srand(20200922); // seed������ ���� ��¥�� �־���.
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
		srand(20200922); // seed������ ���� ��¥�� �־���.
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
		srand(20200922); // seed������ ���� ��¥�� �־���.
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
		srand(20200922); // seed������ ���� ��¥�� �־���.
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



