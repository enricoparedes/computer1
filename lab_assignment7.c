/*  Enrico Paredes
    LAB 7
    03/08/2024
                    */


#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, swapCount = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapCount++;
            }
        }
    }
    swaps[n] = swapCount; // storing the total number of swaps
}

void printSwaps(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n; i++) {
        int swapCount = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
        swaps[arr[i]] = swapCount;
    }
    swaps[n] = 0; // reset the total number of swaps for next iteration
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[n1+1]; // to store the number of swaps for each element and the total swaps
    int swaps2[n2+1]; // to store the number of swaps for each element and the total swaps
    
    printf("array1:\n");
    printSwaps(array1, n1, swaps1);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("total # of swaps: %d\n\n", swaps1[n1]);

    printf("array2:\n");
    printSwaps(array2, n2, swaps2);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("total # of swaps: %d\n", swaps2[n2]);

    return 0;
}
