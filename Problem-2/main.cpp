#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <chrono>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void displayArray(int arr[], int n, const std::string& message) {
    std::cout << message << ": ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void mergeHelper(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int B[high + 1];
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }
    for (; i <= mid; i++)
        B[k++] = arr[i];
    for (; j <= high; j++)
        B[k++] = arr[j];
    for (i = low; i <= high; i++)
        arr[i] = B[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeHelper(arr, low, mid, high);
    }
}

std::vector<int> generateRandomDeliveryTimes(int size, int upperLimit, int seed = 42) {
    srand(seed);
    std::vector<int> deliveryTimes(size);
    for (int i = 0; i < size; i++) {
        deliveryTimes[i] = rand() % (upperLimit - 20 + 1) + 20;
    }
    return deliveryTimes;
}

void compareSortingAlgorithms(int size, int upperLimit, bool displaySortedArray) {
    std::vector<int> deliveryTimes = generateRandomDeliveryTimes(size, upperLimit);
    std::vector<int> bubbleArray = deliveryTimes;

    auto startMerge = std::chrono::high_resolution_clock::now();
    mergeSort(deliveryTimes.data(), 0, deliveryTimes.size() - 1);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mergeDuration = endMerge - startMerge;

    auto startBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleArray.data(), bubbleArray.size());
    auto endBubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> bubbleDuration = endBubble - startBubble;

    std::cout << "Size: " << size << "\n";
    std::cout << "Merge Sort Time: " << mergeDuration.count() << " ms\n";
    std::cout << "Bubble Sort Time: " << bubbleDuration.count() << " ms\n";

    if (displaySortedArray) {
        displayArray(deliveryTimes.data(), deliveryTimes.size(), "Sorted Array (Merge Sort)");
        displayArray(bubbleArray.data(), bubbleArray.size(), "Sorted Array (Bubble Sort)");
    }
    std::cout << std::endl;
}

int main() {
    int upperLimit = 90;
    compareSortingAlgorithms(10, upperLimit, true);
    compareSortingAlgorithms(100, upperLimit, true);
    compareSortingAlgorithms(1000, upperLimit, false);
    return 0;
}