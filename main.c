#include <stdio.h>
#include <stdlib.h>

// Function to calculate the mean
double calculate_mean(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the median
double calculate_median(int arr[], int size) {
    // Sorting the array first
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // If the size is odd
    if (size % 2 != 0) {
        return arr[size / 2];
    }
    // If the size is even
    return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

// Function to calculate the mode
void calculate_mode(int arr[], int size) {
    int max_count = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }
    printf("Mode(s): ");
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == max_count) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 5, 6, 7, 4, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Mean: %.2f\n", calculate_mean(arr, size));
    printf("Median: %.2f\n", calculate_median(arr, size));
    calculate_mode(arr, size);

    return 0;
}