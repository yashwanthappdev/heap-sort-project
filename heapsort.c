/* ============================================================
   Mini Project: Implementation and Performance Analysis of Heap Sort Algorithm using Binary Heap Data Structure
   Algorithm   : Heap Sort
   Author      : YASHWANTH P  |  R24EJ162
   Date        : 18-05-2026
   Description : Program to sort elements using Heap Sort Algorithm
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* ============================================================
   Function Name : heapify
   Purpose       : Maintains the Max Heap property
   ============================================================ */
void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    /* Check if left child is greater than root */
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    /* Check if right child is greater than largest */
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    /* Swap and continue heapifying if needed */
    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}

/* ============================================================
   Function Name : heapSort
   Purpose       : Sorts the array using Heap Sort
   ============================================================ */
void heapSort(int arr[], int size) {
    int i;

    /* Build Max Heap */
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    /* Extract elements one by one from heap */
    for (i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        /* Heapify reduced heap */
        heapify(arr, i, 0);
    }
}

/* ============================================================
   Function Name : printArray
   Purpose       : Displays array elements
   ============================================================ */
void printArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* ============================================================
   Main Function
   Purpose : Reads input, sorts array, and displays output
   ============================================================ */
int main() {
    int arr[MAX_SIZE];
    int size, i;

    /* Read number of elements */
    printf("Enter number of elements: ");
    scanf("%d", &size);

    /* Validate array size */
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size!\n");
        return 1;
    }

    /* Read array elements */
    printf("Enter array elements:\n");

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    /* Display original array */
    printf("\nOriginal Array:\n");
    printArray(arr, size);

    /* Perform Heap Sort */
    heapSort(arr, size);

    /* Display sorted array */
    printf("\nSorted Array:\n");
    printArray(arr, size);

    return 0;
}
