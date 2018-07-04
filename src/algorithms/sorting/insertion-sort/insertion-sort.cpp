#include <iostream>

using namespace std;

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void insertionSort(int arr[], int arrSize) {
	if (arrSize <= 1) return;

	for (int i = 1; i < arrSize; i++) {
		int currentIndex = i;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[currentIndex] < arr[j]) {
				swap(arr, currentIndex, j);
				currentIndex = j;
			}
		}
	}
}

int main() {
	int arr[] = {5, 4, 3, 2, 1, -1, 0, 5, -2};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, arrSize);

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}