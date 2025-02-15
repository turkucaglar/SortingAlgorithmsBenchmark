#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
int t = *a;
*a = *b;
*b = t;
}
void bubbleSort(int arr[], int size) { (int i = 0; i < size - 1; i++) { (int j = 0; j < size - i - 1; j++) {
for
for
if (arr[j] > arr[j + 1]) {
swap(&arr[j], &arr[j + 1]);
}
}
} }
void selectionSort(int arr[], int size) {
int i, j, min_idx;
for (i = 0; i < size - 1; i++) {
min_idx = i;
for (j = i + 1; j < size; j++) {
if (arr[j] < arr[min_idx]) {
min_idx = j;
}
}
swap(&arr[min_idx], &arr[i]);
} }
int medianOfThree(int array[], int low, int high) {
int mid = low + (high - low) / 2;
if (array[low] > array[mid])
swap(&array[low], &array[mid]); if
(array[low] > array[high])
swap(&array[low], &array[high]); if
(array[mid] > array[high])
swap(&array[mid], &array[high]);
return mid; }
int partition(int array[], int low, int high) {
int pivotIndex = medianOfThree(array, low, high);
int pivot = array[pivotIndex];
int i = (low - 1);
for (int j = low; j < high; j++) {
if (array[j] <= pivot) {
i++;
swap(&array[i], &array[j]);
}
}
swap(&array[i + 1], &array[high]);
return (i + 1);
}
void quickSort(int array[], int low, int high) {
if (low < high) {
int pi = partition(array, low, high);
quickSort(array, low, pi - 1); quickSort(array,
pi + 1, high);
} }
void generateSortedArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
arr[i] = i + 1;
} }
void generateReverseSortedArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
arr[i] = size - i;
} }
void generateRandomArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
arr[i] = rand() % 9999 + 1;
} }
void measureTime(void (*sortFunc)(int[], int), int arr[], int size,
const char *sortName, const char *caseName) {
clock_t start_time, end_time;
start_time = clock();
sortFunc(arr, size - 1); end_time
= clock();
printf("%s - %s Case: Time taken: %f seconds\n"
, sortName, caseName,
(double)(end_time - start_time) / CLOCKS_PER_SEC);
}
void quickTime(void (*sortFunc)(int[], int, int), int arr[], int size,
const char *sortName, const char *caseName) {
clock_t start_time, end_time;
start_time = clock();
sortFunc(arr, 0, size); end_time
= clock();
printf("%s - %s Case: Time taken: %f seconds\n"
, sortName, caseName,
(double)(end_time - start_time) / CLOCKS_PER_SEC);
}
void runQuickCases(void (*sortFunc)(int[], int, int), int arr[], int
size, const char *sortName) {
printf("%s:\n"
, sortName);
generateSortedArray(arr, size);
quickTime(sortFunc, arr, size, sortName, "Best");
generateReverseSortedArray(arr, size);
quickTime(sortFunc, arr, size, sortName, "Worst");
generateRandomArray(arr, size);
quickTime(sortFunc, arr, size, sortName, "Average");
printf("\n");
}
void runSortingCases(void (*sortFunc)(int[], int), int arr[], int size,
const char *sortName) {
printf("%s:\n"
, sortName);
generateSortedArray(arr, size);
measureTime(sortFunc, arr, size, sortName, "Best");
generateReverseSortedArray(arr, size);
measureTime(sortFunc, arr, size, sortName, "Worst");
generateRandomArray(arr, size);
measureTime(sortFunc, arr, size, sortName, "Average");
printf("\n");
}
int main() {
srand(time(NULL));
int size = 1000000;
int bubbleData[size];
int selectionData[size];
int *quickData = malloc(size * sizeof(int));
if (quickData == NULL) {
printf("Out of memory! The program is terminating.\n");
return -1;
}
runSortingCases(bubbleSort, bubbleData, size, "Bubble Sort");
runSortingCases(selectionSort, selectionData, size, "Selection
Sort");
runQuickCases(quickSort, quickData, size, "Quick Sort");
free(quickData);
return 0;
}
