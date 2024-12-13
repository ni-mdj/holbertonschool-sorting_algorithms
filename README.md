# Sorting Algorithms in C

This project implements four different sorting algorithms in C: **Bubble Sort**, **Selection Sort**, **Insertion Sort**, and **Merge Sort**. It also covers the basics of Big O notation, how to evaluate the time complexity of sorting algorithms, and the concept of stable sorting.

## Algorithms Implemented

1. **Bubble Sort**
2. **Selection Sort**
3. **Insertion Sort**
4. **Merge Sort**

## Big O Notation & Time Complexity

- **Bubble Sort**: O(n^2) in the worst and average case, O(n) in the best case (when the list is already sorted).
- **Selection Sort**: O(n^2) in all cases (best, average, and worst).
- **Insertion Sort**: O(n^2) in the worst case, O(n) in the best case.
- **Merge Sort**: O(n log n) in all cases.

### Time Complexity Analysis

- **O(n^2)**: The algorithm performance increases quadratically with input size. Common in algorithms with nested loops.
- **O(n log n)**: The algorithm grows slower, making it more efficient for large inputs.

## Stable Sorting Algorithms

A **stable sorting algorithm** maintains the relative order of records with equal keys. For example, if two elements have the same value, their order remains unchanged after sorting.

- **Stable Algorithms**: Insertion Sort, Merge Sort.
- **Unstable Algorithms**: Bubble Sort, Selection Sort.

## How to Select the Best Algorithm?

- **For small datasets**: Simple algorithms like Insertion Sort or Bubble Sort may be sufficient.
- **For larger datasets**: Use algorithms with O(n log n) complexity, such as Merge Sort, for better performance.
- **For partially sorted data**: Insertion Sort can perform very efficiently with already sorted or nearly sorted data.

## Example Usage

```c
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Example: Sorting with Bubble Sort
    bubbleSort(arr, n);

    printf("Sorted array using Bubble Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
