#include <iostream>

using namespace std;

int left(int i) {
	return i * 2 + 1;
}

int right(int i) {
	return i * 2 + 2;
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void maxHeapify(int arr[], int arrSize, int index) {
	int l = left(index);
	int r = right(index);
	int largest = index;
	
	if (l < arrSize && arr[l] > arr[index]) {
		largest = l;
	}
	if (r < arrSize && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != index) {
		swap(arr, index, largest);
		maxHeapify(arr, arrSize, largest);
	}
}

void buildMaxHeap(int arr[], int arrSize) {
	for (int i = arrSize/2; i >= 0; i--) {
		maxHeapify(arr, arrSize, i);
	}
}

void heapSort(int arr[], int arrSize) {
	if (arrSize > 1) {
		swap(arr, 0, arrSize - 1);
		arrSize--;
		maxHeapify(arr, arrSize, 0);
		heapSort(arr, arrSize);
	}
}

int main() {
	int arr[] = {5, 4, 3, 2, 1, -1, 0, 6, -2};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	buildMaxHeap(arr, arrSize);
	heapSort(arr, arrSize);

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
