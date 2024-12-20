#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const std::vector<int> &arr) {
    for (const int &value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    std::vector<int> arr(size);

    std::cout << "Enter " << size << " elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}